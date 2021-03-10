#include "LayoutManager.h"
#include "Utility.h"
namespace tggd::common
{
	Layout* LayoutManager::ParseDescriptor(const std::string&, const nlohmann::json& properties)
	{
		return new Layout(finishManager, spriteManager, colorManager, fontManager, stringStore, intStore, flagStore, tggd::data::JSONUtility::LoadJSON(properties));
	}

	LayoutManager::LayoutManager
	(
		FinishManager& finishManager,
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const FontManager& fontManager,
		const tggd::data::IDataStore<std::string>& stringStore,
		const tggd::data::IDataStore<int>& intStore,
		const tggd::data::IDataStore<bool>& flagStore
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