#pragma once
#include <map>
#include <string>
#include "Sprite.h"
#include "TextureManager.h"
#include "FinishManager.h"
#include "IDataStore.h"
namespace tggd::graphics
{
	class SpriteManager: public tggd::common::Finisher, public tggd::data::IDataStore<Sprite>
	{
		SpriteManager() = delete;
		SpriteManager(const SpriteManager&) = delete;
		SpriteManager(SpriteManager&&) = delete;
		SpriteManager& operator=(const SpriteManager&) = delete;
		SpriteManager& operator=(SpriteManager&&) = delete;
	private:
		std::map<std::string, const Sprite*> sprites;
		void AddSprite(const std::string&, const Sprite*);
	public:
		SpriteManager(tggd::common::FinishManager&);
		const Sprite& operator[](const std::string&) const;
		void Start(const TextureManager&, const std::string&);
		void Finish();
	};
}