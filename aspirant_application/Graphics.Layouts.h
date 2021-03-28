#pragma once
#include <string>
#include <SDL.h>
#include <optional>
namespace graphics::Layouts
{
	void Draw(SDL_Renderer*, const std::string&);
	void Start(const std::string&);

	std::optional<int> GetMenuValue(const std::string&, const std::string&);
	void NextMenuIndex(const std::string&, const std::string&);
	void PreviousMenuIndex(const std::string&, const std::string&);

	void SetMenuItemText(const std::string&, const std::string&, const std::string&);
}
