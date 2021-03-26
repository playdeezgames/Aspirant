#include "Graphics.Colors.h"
#include "Data.JSON.h"
#include <map>
#include <vector>
namespace graphics::Colors
{
	const std::string PROPERTY_RED = "r";
	const std::string PROPERTY_GREEN = "g";
	const std::string PROPERTY_BLUE = "b";
	const std::string PROPERTY_ALPHA = "a";

	static nlohmann::json table;
	
	static SDL_Color ParseDescriptor(const nlohmann::json& properties)
	{
		SDL_Color result;
		result.r = (Uint8)properties[PROPERTY_RED];
		result.g = (Uint8)properties[PROPERTY_GREEN];
		result.b = (Uint8)properties[PROPERTY_BLUE];
		result.a = (Uint8)properties[PROPERTY_ALPHA];
		return result;
	}

	void Start(const std::string& fileName)
	{
		table = data::JSON::Load(fileName);
	}

	SDL_Color Get(const std::string& key)
	{
		return ParseDescriptor(table[key]);
	}
}