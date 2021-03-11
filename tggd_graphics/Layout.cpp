#include "Layout.h"
#include "Utility.h"
#include "StaticImage.h"
#include "StaticText.h"
namespace tggd::graphics
{
	Layout::Layout
	(
		tggd::common::FinishManager& finishManager
	)
		: drawnItems()
	{
		finishManager.Add(this);
	}

	const std::string PROPERTY_TYPE="type";
	const std::string TYPE_STATIC_IMAGE = "StaticImage";
	const std::string TYPE_STATIC_TEXT = "StaticText";
	
	Layout::Layout
	(
		tggd::common::FinishManager& finishManager,
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const FontManager& fontManager,
		const tggd::data::IDataStore<std::string>& stringStore,
		const tggd::data::IDataStore<int>& intStore,
		const tggd::data::IDataStore<bool>& flagStore,
		const nlohmann::json& itemDescriptors
	)
		: drawnItems()
	{
		finishManager.Add(this);
		for (auto& itemDescriptor : itemDescriptors)
		{
			std::string itemType = itemDescriptor[PROPERTY_TYPE];
			if (itemType == TYPE_STATIC_IMAGE)
			{
				drawnItems.push_back
				(
					new StaticImage(stringStore, intStore, spriteManager, colorManager, itemDescriptor)
				);
			}
			else if (itemType == TYPE_STATIC_TEXT)
			{
				drawnItems.push_back
				(
					new StaticText(stringStore, intStore, flagStore, fontManager, itemDescriptor)
				);
			}
		}
	}

	void Layout::Draw(SDL_Renderer* renderer) const
	{
		for (auto& item : drawnItems)
		{
			item->Draw(renderer);
		}
	}

	void Layout::Finish()
	{
		for (auto& item : drawnItems)
		{
			tggd::common::FinishUtility::SafeDelete(item);
		}
		drawnItems.clear();
	}

	void Layout::Add(Drawn* drawn)
	{
		drawnItems.remove(drawn);
		drawnItems.push_back(drawn);
	}
}