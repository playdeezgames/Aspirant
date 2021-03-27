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
		nlohmann::json& model
	)
		: model(model)
	{
	}

	void Layout::Draw(SDL_Renderer* renderer) const
	{
		for (auto& itemDescriptor : model)
		{
			std::string itemType = itemDescriptor[PROPERTY_TYPE];
			if (itemType == TYPE_STATIC_IMAGE)
			{
				graphics::Image(itemDescriptor).Draw(renderer);
			}
			else if (itemType == TYPE_STATIC_TEXT)
			{
				graphics::Text(itemDescriptor).Draw(renderer);
			}
		}
	}
}