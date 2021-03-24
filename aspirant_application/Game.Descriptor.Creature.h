#pragma once
#include "Game.Descriptor.Common.h"
namespace game::descriptor
{
	class Creature : public Common
	{
	protected:
		Creature(const std::string&, const nlohmann::json&);
	public:
		game::object::Common* CreateObject() const;
		static Common* FromNameAndProperties(const std::string&, const nlohmann::json&);
	};
}
