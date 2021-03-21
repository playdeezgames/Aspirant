#include "LayoutManager.h"
#include "JSONUtility.h"
#include "FinishManager.h"
#include "FinishUtility.h"
namespace tggd::graphics::LayoutManager
{
	Layout* ParseDescriptor(const std::string&, const nlohmann::json& properties)
	{
		return new Layout(tggd::data::JSONUtility::LoadJSON(properties));
	}

	static std::string ParseKey(const nlohmann::json& key)
	{
		return key;
	}

	static std::map<std::string, Layout*> descriptors;
	static std::vector<std::string> identifiers;

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	static void Finish()
	{
		tggd::common::FinishUtility::SafeDeleteMap(descriptors);
	}

	void Start(const std::string& fileName)
	{
		tggd::common::FinishManager::Add(Finish);
		nlohmann::json properties = tggd::data::JSONUtility::LoadJSON(fileName);
		for (auto& item : properties.items())
		{
			auto identifier = ParseKey(item.key());
			identifiers.push_back(identifier);
			descriptors[identifier] =
				ParseDescriptor(identifier, item.value());
		}
	}

	const Layout& Get(const std::string& key)
	{
		return *descriptors[key];
	}

}