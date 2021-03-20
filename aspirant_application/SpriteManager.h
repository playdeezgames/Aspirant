#pragma once
#include <string>
#include "Sprite.h"
namespace tggd::graphics::SpriteManager
{
	const Sprite& Get(const std::string&);
	void Start(const std::string&);
}