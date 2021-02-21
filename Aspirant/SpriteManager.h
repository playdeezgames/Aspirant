#pragma once
#include <map>
#include <string>
#include "Sprite.h"
#include "TextureManager.h"
#include "FinishManager.h"
#include "IDataStore.h"
namespace tggd::common
{
	class SpriteManager: public Finisher, public IDataStore<Sprite>
	{
	private:
		std::map<std::string, const Sprite*> sprites;
		void AddSprite(const std::string&, const Sprite*);
	public:
		SpriteManager(FinishManager&);
		const Sprite& Get(const std::string&) const;
		void Start(const TextureManager&, const std::string&);
		void Finish();
	};
}