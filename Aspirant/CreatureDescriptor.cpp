#include "CreatureDescriptor.h"
namespace aspirant
{
	CreatureDescriptor::CreatureDescriptor(const nlohmann::json& properties)
		: BaseDescriptor(properties)
	{

	}

	BaseGameObject* CreatureDescriptor::LoadGameObject(const nlohmann::json&) const
	{
		throw "NOTIMPL";
	}

	BaseGameObject* CreatureDescriptor::NewGameObject() const
	{
		throw "NOTIMPL";
	}
}