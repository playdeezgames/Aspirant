#include "Common.Utility.h"
#include "Graphics.Fonts.h"
#include "Common.Properties.h"
#include "Graphics.Properties.h"
#include "Data.String.h"
namespace graphics::Text
{
	void Draw(SDL_Renderer* renderer, const nlohmann::json& model)
	{
		if ((bool)model[graphics::Properties::DROP_SHADOW])
		{
			graphics::Fonts::Get(
				data::String(model[graphics::Properties::FONT]))
				.WriteText(
					renderer, 
					common::XY<int>(
						(int)model[common::Properties::X] + (int)model[graphics::Properties::DROP_SHADOW_X], 
						(int)model[common::Properties::Y] + (int)model[graphics::Properties::DROP_SHADOW_Y]),
					data::String(model[graphics::Properties::TEXT]),
					data::String(model[graphics::Properties::DROP_SHADOW_COLOR]),
					(HorizontalAlignment)(int)model[graphics::Properties::HORIZONTAL_ALIGNMENT]);
		}
		graphics::Fonts::Get(
			data::String(model[graphics::Properties::FONT]))
			.WriteText(
				renderer, 
				common::XY<int>(model[common::Properties::X], model[common::Properties::Y]),
				data::String(model[graphics::Properties::TEXT]),
				data::String(model[graphics::Properties::COLOR]),
				(HorizontalAlignment)(int)model[graphics::Properties::HORIZONTAL_ALIGNMENT]);
	}
}
