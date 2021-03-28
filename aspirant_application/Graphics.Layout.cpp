#include "Common.Utility.h"
#include "Common.Finisher.h"
#include "Common.Properties.h"
#include "Graphics.Types.h"
#include <map>
#include "json.hpp"
#include <SDL.h>
namespace graphics::Menu { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace graphics::Image { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace graphics::Text { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace renderer::editor::RoomCellObjects { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace renderer::editor::PickDescriptor { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace renderer::editor::Room { void Draw(SDL_Renderer*, const nlohmann::json&); }
namespace graphics::Layout
{
	static std::map<std::string, void(*)(SDL_Renderer*, const nlohmann::json&)> table =
	{
		{graphics::Types::IMAGE, graphics::Image::Draw},
		{graphics::Types::MENU, graphics::Menu::Draw},
		{graphics::Types::TEXT, graphics::Text::Draw},
		{graphics::Types::ROOM_EDITOR, renderer::editor::Room::Draw},
		{graphics::Types::DESCRIPTOR_PALETTE, renderer::editor::PickDescriptor::Draw},
		{graphics::Types::CELL_BROWSE, renderer::editor::RoomCellObjects::Draw}
	};

	void Draw(SDL_Renderer* renderer, const nlohmann::json& model)
	{
		for (auto& drawn : model)
		{
			std::string drawnType = drawn[common::Properties::TYPE];
			auto drawer = table.find(drawnType);
			if (drawer != table.end())
			{
				drawer->second(renderer, drawn);
			}
		}
	}
}