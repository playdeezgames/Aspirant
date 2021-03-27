#include "Graphics.Layout.h"
#include "Common.Utility.h"
#include "Graphics.Image.h"
#include "Graphics.Text.h"
#include "Common.Finisher.h"
#include "Common.Properties.h"
#include "Graphics.Types.h"
namespace graphics::Layout
{
	void Draw(SDL_Renderer* renderer, const nlohmann::json& model)
	{
		for (auto& itemDescriptor : model)
		{
			std::string itemType = itemDescriptor[common::Properties::TYPE];
			if (itemType == graphics::Types::IMAGE)
			{
				graphics::Image::Draw(renderer, itemDescriptor);
			}
			else if (itemType == graphics::Types::TEXT)
			{
				graphics::Text::Draw(renderer, itemDescriptor);
			}
		}
	}
}