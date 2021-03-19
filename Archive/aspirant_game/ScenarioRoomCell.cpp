#include "ScenarioRoomCell.h"
namespace aspirant::game
{
	nlohmann::json ScenarioRoomCell::CellFlagToJSON(const ScenarioRoomCellFlags& cellFlag) const
	{
		throw "NOT IMPLEMENTED";
	}

	ScenarioRoomCellFlags ScenarioRoomCell::CellFlagFromJSON(const nlohmann::json& properties)
	{
		throw "NOT IMPLEMENTED";
	}

	const std::string PROPERTY_TYPE = "type";

	ScenarioObjectInstance* ScenarioRoomCell::ObjectFromJSON(const nlohmann::json& properties)
	{
		auto typeName = properties[PROPERTY_TYPE];
		auto descriptor = descriptors.GetDescriptor(typeName);
		auto obj = descriptor->CreateObject();
		obj->FromJSON(properties);
		return obj;
	}

	nlohmann::json ScenarioRoomCell::ObjectToJSON(const ScenarioObjectInstance* obj) const
	{
		return obj->ToJSON();
	}

	bool ScenarioRoomCell::CanCover(const ScenarioObjectInstance* newObject, const ScenarioObjectInstance* oldObject) const
	{
		return newObject->CanCover(oldObject);
	}

}