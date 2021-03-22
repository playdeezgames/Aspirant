#include "Graphics.Colors.h"
#include "JSONUtility.h"
#include <map>
#include <vector>
namespace graphics::Colors
{
	const std::string PROPERTY_RED = "r";
	const std::string PROPERTY_GREEN = "g";
	const std::string PROPERTY_BLUE = "b";
	const std::string PROPERTY_ALPHA = "a";
	
	static SDL_Color ParseDescriptor(const std::string&, const nlohmann::json& properties)
	{
		SDL_Color result;
		result.r = (Uint8)properties[PROPERTY_RED];
		result.g = (Uint8)properties[PROPERTY_GREEN];
		result.b = (Uint8)properties[PROPERTY_BLUE];
		result.a = (Uint8)properties[PROPERTY_ALPHA];
		return result;
	}

	static std::string ParseKey(const nlohmann::json& key)
	{
		return key;
	}

	static std::map<std::string, SDL_Color> descriptors;
	static std::vector<std::string> identifiers;

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	void Start(const std::string& fileName)
	{
		nlohmann::json properties = tggd::data::JSONUtility::LoadJSON(fileName);
		for (auto& item : properties.items())
		{
			auto identifier = ParseKey(item.key());
			identifiers.push_back(identifier);
			descriptors[identifier] =
				ParseDescriptor(identifier, item.value());
		}
	}

	const SDL_Color& Get(const std::string& key)
	{
		return descriptors[key];
	}
}