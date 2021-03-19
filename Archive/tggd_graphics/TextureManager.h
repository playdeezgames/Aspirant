#pragma once
#include <SDL.h>
#include <map>
#include <string>
#include "FinishManager.h"
namespace tggd::graphics
{
	class TextureManager: public tggd::common::Finisher
	{
		TextureManager() = delete;
		TextureManager(const TextureManager&) = delete;
		TextureManager(TextureManager&&) = delete;
		TextureManager& operator=(const TextureManager&) = delete;
		TextureManager& operator=(TextureManager&&) = delete;
	private:
		std::map<std::string, SDL_Texture*> textures;
		void Add(const std::string&, SDL_Texture*);
	public:
		TextureManager(tggd::common::FinishManager&);
		void Start(SDL_Renderer*, const std::string&);
		void Finish();
		SDL_Texture* Get(const std::string&) const;
	};
}

