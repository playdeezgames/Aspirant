#include "Graphics.Textures.h"
#include "Utility.h"
#include <SDL_image.h>
#include "Data.JSON.h"
#include "FinishManager.h"
#include <map>
namespace graphics::Textures
{
	static std::map<std::string, SDL_Texture*> textures;

	static void Finish()
	{
		for (auto& entry : textures)
		{
			if (entry.second)
			{
				SDL_DestroyTexture(entry.second);
				entry.second = nullptr;
			}
		}
		textures.clear();
	}

	static void Add(const std::string& name, SDL_Texture* texture)
	{
		textures[name] = texture;
	}

	void Start(SDL_Renderer* renderer, const std::string& fileName)
	{
		tggd::common::FinishManager::Add(Finish);
		auto properties = data::JSON::Load(fileName);
		for (auto& entry : properties.items())
		{
			std::string imageFileName = entry.value();
			Add(entry.key(), IMG_LoadTexture(renderer, imageFileName.c_str()));
		}
	}

	SDL_Texture* Get(const std::string& name)
	{
		auto iter = textures.find(name);
		if (iter != textures.end())
		{
			return iter->second;
		}
		return nullptr;
	}

}