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
	private:
		std::map<std::string, const Sprite*> sprites;
		void AddSprite(const std::string&, const Sprite*);
	public:
		SpriteManager(tggd::common::FinishManager&);
		const Sprite& Get(const std::string&) const;
		void Start(const TextureManager&, const std::string&);
		void Finish();
	};
}