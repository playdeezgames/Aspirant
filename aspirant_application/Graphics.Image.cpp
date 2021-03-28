#include "Common.Properties.h"
#include "Common.Utility.h"
#include "Common.XY.h"
#include "Data.String.h"
#include "Graphics.Colors.h"
#include "Graphics.Properties.h"
#include "Graphics.Sprites.h"
namespace graphics::Image
{
	void Draw(SDL_Renderer* renderer, const nlohmann::json& model)
	{
		Sprites::Get(data::String(model[Properties::SPRITE]))
			.Draw
			(
				renderer,
				common::XY<int>(
					(int)model[common::Properties::X], 
					(int)model[common::Properties::Y]),
				::graphics::Colors::Get(data::String(model[Properties::COLOR]))
			);
	}
}
