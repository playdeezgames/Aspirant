#pragma once
#include "Game.Descriptor.Common.h"
namespace game::descriptor
{
	class Terrain : public Common
	{
	protected:
		Terrain(const std::string&, const nlohmann::json&);
	public:
		game::object::Common* CreateObject() const;
		static Common* FromNameAndProperties(const std::string&, const nlohmann::json&);
	};
}
