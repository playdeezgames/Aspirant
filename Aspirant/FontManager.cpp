#include "FontManager.h"
namespace tggd::common
{
	SpriteFont* FontManager::ParseDescriptor(const nlohmann::json& properties)
	{
		return new SpriteFont(spriteManager, colorManager, properties);
	}

	FontManager::FontManager
	(
		FinishManager& finishManager,
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