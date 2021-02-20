#include "LayoutManager.h"
#include "Utility.h"
namespace tggd::common
{
	std::string LayoutManager::ParseKey(const std::string& key)
	{
		return key;
	}

	Layout* LayoutManager::ParseDescriptor(const nlohmann::json& properties)
	{
		return new Layout(finishManager, spriteManager, colorManager, fontManager, stringManager, Utility::LoadJSON(properties));
	}

	LayoutManager::LayoutManager
	(
		FinishManager& finishManager,
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const FontManager& fontManager,
		const StringManager& stringManager
	)
		: BaseDescriptorManager(finishManager)
		, finishManager(finishManager)
		, spriteManager(spriteManager)
		, colorManager(colorManager)
		, fontManager(fontManager)
		, stringManager(stringManager)
	{

	}

}