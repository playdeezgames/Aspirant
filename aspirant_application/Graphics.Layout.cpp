#include "Graphics.Layout.h"
#include "Common.Utility.h"
#include "Graphics.Image.h"
#include "Graphics.Text.h"
#include "Common.Finisher.h"
namespace graphics
{
	const std::string PROPERTY_TYPE = "type";
	const std::string TYPE_STATIC_IMAGE = "StaticImage";
	const std::string TYPE_STATIC_TEXT = "StaticText";

	Layout::Layout
	(
		const nlohmann::json& itemDescriptors
	)
		: drawnItems()
	{
		for (auto& itemDescriptor : itemDescriptors)
		{
			std::string itemType = itemDescriptor[PROPERTY_TYPE];
			if (itemType == TYPE_STATIC_IMAGE)
			{
				drawnItems.push_back
				(
					new graphics::Image(itemDescriptor)
				);
			}
			else if (itemType == TYPE_STATIC_TEXT)
			{
				drawnItems.push_back
				(
					new graphics::Text(itemDescriptor)
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
			common::Finisher::SafeDelete(item);
		}
		drawnItems.clear();
	}

	void Layout::Add(Drawn* drawn)
	{
		drawnItems.remove(drawn);
		drawnItems.push_back(drawn);
	}
}