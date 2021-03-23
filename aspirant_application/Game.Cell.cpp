#include "Game.Cell.h"
#include "Game.Descriptors.h"
namespace game
{
	const std::string PROPERTY_TYPE = "type";

	::game::object::Common* Cell::ObjectFromJSON(const nlohmann::json& properties)
	{
		auto obj = ::game::Descriptors::Get(properties[PROPERTY_TYPE])->CreateObject();
		obj->FromJSON(properties);
		return obj;
	}

	nlohmann::json Cell::ObjectToJSON(const ::game::object::Common* obj) const
	{
		return obj->ToJSON();
	}

	bool Cell::CanCover(const ::game::object::Common* newObject, const ::game::object::Common* oldObject) const
	{
		return newObject->CanCover(oldObject);
	}

}