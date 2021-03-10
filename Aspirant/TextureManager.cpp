#include "TextureManager.h"
#include "Utility.h"
#include <SDL_image.h>
#include "JSONUtility.h"
namespace tggd::common
{
	TextureManager::TextureManager(FinishManager& finishManager)
		: textures()
	{
		finishManager.Add(this);
	}

	void TextureManager::Start(SDL_Renderer* renderer, const std::string& fileName)
	{
		auto properties = JSONUtility::LoadJSON(fileName);
		for (auto& entry : properties.items())
		{
			std::string imageFileName = entry.value();
			Add(entry.key(), IMG_LoadTexture(renderer, imageFileName.c_str()));
		}
	}

	void TextureManager::Finish()
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

	SDL_Texture* TextureManager::Get(const std::string& name) const
	{
		auto iter = textures.find(name);
		if (iter != textures.end())
		{
			return iter->second;
		}
		return nullptr;
	}

	void TextureManager::Add(const std::string& name, SDL_Texture* texture)
	{
		textures[name] = texture;
	}
}