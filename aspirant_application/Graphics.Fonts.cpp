#include "Graphics.Fonts.h"
#include "Data.JSON.h"
#include "FinishUtility.h"
#include "Common.Finishers.h"
namespace graphics::Fonts
{
	static tggd::graphics::SpriteFont* ParseDescriptor(const std::string&, const nlohmann::json& properties)
	{
		return new tggd::graphics::SpriteFont(properties);
	}

	static std::map<std::string, tggd::graphics::SpriteFont*> descriptors;
	static std::vector<std::string> identifiers;

	const tggd::graphics::SpriteFont& Get(const std::string& key)
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