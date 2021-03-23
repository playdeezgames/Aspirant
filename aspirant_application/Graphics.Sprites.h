#pragma once
#include <string>
#include "Graphics.Sprite.h"
namespace graphics::Sprites
{
	const Sprite& Get(const std::string&);
	void Start(const std::string&);
}