#include "Layout.h"
#include "Utility.h"
#include "StaticImage.h"
#include "StaticText.h"
namespace tggd::common
{
	Layout::Layout
	(
		FinishManager& finishManager
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
		FinishManager& finishManager,
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const FontManager& fontManager,
		const IDataStore<std::string>& stringStore,
		const IDataStore<int>& intStore,
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
					new StaticText(stringStore, intStore, fontManager, itemDescriptor)
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
			Utility::SafeDelete(item);
		}
		drawnItems.clear();
	}

	void Layout::Add(Drawn* drawn)
	{
		drawnItems.remove(drawn);
		drawnItems.push_back(drawn);
	}
}