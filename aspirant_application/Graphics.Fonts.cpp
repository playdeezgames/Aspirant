#include "Graphics.Fonts.h"
#include "Data.JSON.h"
#include "FinishUtility.h"
#include "Common.Finishers.h"
namespace graphics::Fonts
{
	static graphics::Font* ParseDescriptor(const std::string&, const nlohmann::json& properties)
	{
		return new graphics::Font(properties);
	}

	static std::map<std::string, graphics::Font*> descriptors;
	static std::vector<std::string> identifiers;

	const graphics::Font& Get(const std::string& key)
	{
		return *descriptors[key];
	}

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	static std::string ParseKey(const nlohmann::json& key)
	{
		return key;
	}

	static void Finish()
	{
		tggd::common::FinishUtility::SafeDeleteMap(descriptors);
	}

	void Start(const std::string& fileName)
	{
		::common::Finishers::Add(Finish);
		nlohmann::json properties = data::JSON::Load(fileName);
		for (auto& item : properties.items())
		{
			auto identifier = ParseKey(item.key());
			identifiers.push_back(identifier);
			descriptors[identifier] =
				ParseDescriptor(identifier, item.value());
		}
	}

}