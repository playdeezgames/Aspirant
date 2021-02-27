#include "LayoutManager.h"
#include "Utility.h"
namespace tggd::common
{
	Layout* LayoutManager::ParseDescriptor(const nlohmann::json& properties)
	{
		return new Layout(finishManager, spriteManager, colorManager, fontManager, stringStore, intStore, flagStore, Utility::LoadJSON(properties));
	}

	LayoutManager::LayoutManager
	(
		FinishManager& finishManager,
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const FontManager& fontManager,
		const IDataStore<std::string>& stringStore,
		const IDataStore<int>& intStore,
		const IDataStore<bool>& flagStore
	)
		: CommonDescriptorManager(finishManager)
		, finishManager(finishManager)
		, spriteManager(spriteManager)
		, colorManager(colorManager)
		, fontManager(fontManager)
		, stringStore(stringStore)
		, intStore(intStore)
		, flagStore(flagStore)
	{

	}

}