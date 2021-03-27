#include "Graphics.Sprites.h"
#include "Common.Utility.h"
#include "Data.JSON.h"
#include "Graphics.Textures.h"
#include "Common.Properties.h"
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

	void Start(const std::string& fileName)
	{
		nlohmann::json j = data::JSON::Load(fileName);
		for (auto& item : j.items())
		{
			auto& properties = item.value();
			SDL_Texture* texture = ::graphics::Textures::Read(properties[PROPERTY_TEXTURE]);
			SDL_Rect source;
			source.x = properties[common::Properties::X];
			source.y = properties[common::Properties::Y];
			source.w = properties[common::Properties::WIDTH];
			source.h = properties[common::Properties::HEIGHT];
			int offsetX = (properties.count(PROPERTY_OFFSET_X) > 0) ? ((int)properties[PROPERTY_OFFSET_X]) : (0);
			int offsetY = (properties.count(PROPERTY_OFFSET_Y) > 0) ? ((int)properties[PROPERTY_OFFSET_Y]) : (0);
			common::XY<int> offset(offsetX, offsetY);
			Sprite sprite(texture, source, offset);
			Add(item.key(), sprite);
		}
	}
}
