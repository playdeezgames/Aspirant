#pragma once
#include <string>
#include "Graphics.Layout.h"
namespace graphics::Layouts
{
	const graphics::Layout& Get(const std::string&);
	void Start(const std::string&);
}
