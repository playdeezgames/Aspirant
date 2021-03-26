#include "Graphics.Sprites.h"
#include "Common.Utility.h"
#include "Data.JSON.h"
#include "Graphics.Textures.h"
namespace graphics::Sprites
{
	static std::map<std::string, Sprite> sprites;


	static void Add(const std::string& name, const Sprite& sprite)
	{
		sprites[name] = sprite;
	}

	const Sprite& Get(const std::string& name)
	{
		auto iter = sprites.find(name);
		return iter->second;
	}

	const std::string PROPERTY_TEXTURE = "texture";
	const std::string PROPERTY_OFFSET_X = "offset-x";
	const std::string PROPERTY_OFFSET_Y = "offset-y";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";
	const std::string PROPERTY_W = "w";
	const std::string PROPERTY_H = "h";

	void Start(const std::string& fileName)
	{
		nlohmann::json j = data::JSON::Load(fileName);
		for (auto& item : j.items())
		{
			auto& properties = item.value();
			SDL_Texture* texture = ::graphics::Textures::Read(properties[PROPERTY_TEXTURE]);
			SDL_Rect source;
			source.x = properties[PROPERTY_X];
			source.y = properties[PROPERTY_Y];
			source.w = properties[PROPERTY_W];
			source.h = properties[PROPERTY_H];
			int offsetX = (properties.count(PROPERTY_OFFSET_X) > 0) ? ((int)properties[PROPERTY_OFFSET_X]) : (0);
			int offsetY = (properties.count(PROPERTY_OFFSET_Y) > 0) ? ((int)properties[PROPERTY_OFFSET_Y]) : (0);
			common::XY<int> offset(offsetX, offsetY);
			Sprite sprite(texture, source, offset);
			Add(item.key(), sprite);
		}
	}
}
