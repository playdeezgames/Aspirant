#include "ScenarioRoomCell.h"
#include "Game.Descriptors.h"
namespace aspirant::game
{
	const std::string PROPERTY_TYPE = "type";

	::game::object::Common* ScenarioRoomCell::ObjectFromJSON(const nlohmann::json& properties)
	{
		auto obj = ::game::Descriptors::Get(properties[PROPERTY_TYPE])->CreateObject();
		obj->FromJSON(properties);
		return obj;
	}

	nlohmann::json ScenarioRoomCell::ObjectToJSON(const ::game::object::Common* obj) const
	{
		return obj->ToJSON();
	}

	bool ScenarioRoomCell::CanCover(const ::game::object::Common* newObject, const ::game::object::Common* oldObject) const
	{
		return newObject->CanCover(oldObject);
	}

}