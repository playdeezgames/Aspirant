#include "Graphics.Layouts.h"
#include "Data.JSON.h"
#include "Common.Finishers.h"
#include "Common.Finisher.h"
namespace graphics::Layouts
{
	graphics::Layout* ParseDescriptor(const std::string&, const nlohmann::json& properties)
	{
		return new graphics::Layout(data::JSON::Load(properties));
	}

	static std::string ParseKey(const nlohmann::json& key)
	{
		return key;
	}

	static std::map<std::string, graphics::Layout*> descriptors;
	static std::vector<std::string> identifiers;

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	static void Finish()
	{
		common::Finisher::Finish(descriptors);
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

	const graphics::Layout& Get(const std::string& key)
	{
		return *descriptors[key];
	}

}