#include "FontManager.h"
namespace tggd::graphics
{
	SpriteFont* FontManager::ParseDescriptor(const std::string&, const nlohmann::json& properties)
	{
		return new SpriteFont(spriteManager, colorManager, properties);
	}

	FontManager::FontManager
	(
		tggd::common::FinishManager& finishManager,
		const SpriteManager& spriteManager,
		const ColorManager& colorManager
	)
		: CommonDescriptorManager(finishManager)
		, spriteManager(spriteManager)
		, colorManager(colorManager)
	{

	}

	const SpriteFont& FontManager::Get(const std::string& key) const
	{
		return *GetDescriptor(key);
	}
}