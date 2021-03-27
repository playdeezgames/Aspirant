#include "Graphics.Layout.h"
#include "Common.Utility.h"
#include "Graphics.Image.h"
#include "Graphics.Text.h"
#include "Common.Finisher.h"
#include "Common.Properties.h"
#include "Graphics.Types.h"
namespace graphics
{
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
			std::string itemType = itemDescriptor[common::Properties::TYPE];
			if (itemType == graphics::Types::IMAGE)
			{
				graphics::Image(itemDescriptor).Draw(renderer);
			}
			else if (itemType == graphics::Types::TEXT)
			{
				graphics::Text(itemDescriptor).Draw(renderer);
			}
		}
	}
}