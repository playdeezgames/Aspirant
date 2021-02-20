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
		return new Layout(finishManager, spriteManager, colorManager, fontManager, stringStore, intStore, Utility::LoadJSON(properties));
	}

	LayoutManager::LayoutManager
	(
		FinishManager& finishManager,
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const FontManager& fontManager,
		const IDataStore<std::string>& stringStore,
		const IDataStore<int>& intStore
	)
		: BaseDescriptorManager(finishManager)
		, finishManager(finishManager)
		, spriteManager(spriteManager)
		, colorManager(colorManager)
		, fontManager(fontManager)
		, stringStore(stringStore)
		, intStore(intStore)
	{

	}

}