#include "Layout.h"
#include "Utility.h"
#include "StaticImage.h"
#include "StaticText.h"
#include "DynamicText.h"
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
	const std::string TYPE_DYNAMIC_TEXT = "DynamicText";

	Layout::Layout
	(
		FinishManager& finishManager, 
		const SpriteManager& spriteManager,
		const ColorManager& colorManager,
		const FontManager& fontManager,
		const StringManager& stringManager,
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
					new StaticImage(spriteManager, colorManager, itemDescriptor)
				);
			}
			else if (itemType == TYPE_STATIC_TEXT)
			{
				drawnItems.push_back
				(
					new StaticText(fontManager, itemDescriptor)
				);
			}
			else if (itemType == TYPE_DYNAMIC_TEXT)
			{
				drawnItems.push_back
				(
					new DynamicText(fontManager, stringManager, itemDescriptor)
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