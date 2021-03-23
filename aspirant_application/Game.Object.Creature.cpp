#include "Game.Object.Creature.h"
namespace game::object
{
	Creature::Creature(const ::game::descriptor::Creature& descriptor)
		: Common(descriptor)
	{

	}

	bool Creature::CanCover(const Common* obj) const
	{
		return obj != nullptr && obj->IsTerrain();
	}

	bool Creature::IsTerrain() const
	{
		return false;
	}

	bool Creature::IsCreature() const
	{
		return true;
	}

	const std::string PROPERTY_TYPE = "type";

	void Creature::FromJSON(const nlohmann::json&)
	{

	}

	nlohmann::json Creature::ToJSON() const
	{
		nlohmann::json properties;
		properties[PROPERTY_TYPE] = GetDescriptor().GetName();//TODO: move this into base class
		return properties;
	}
}