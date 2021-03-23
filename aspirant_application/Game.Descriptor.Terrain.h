#pragma once
#include "Game.Descriptor.Common.h"
namespace game::descriptor
{
	class Terrain : public Common
	{
	public:
		Terrain(const std::string&, const nlohmann::json&);
		game::object::Common* CreateObject() const;
	};
}
