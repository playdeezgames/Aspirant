#pragma once
#include <string>
#include "Layout.h"
namespace tggd::graphics::LayoutManager
{
	const Layout& Get(const std::string&);
	void Start(const std::string&);
}
