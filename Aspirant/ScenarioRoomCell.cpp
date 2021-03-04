#include "ScenarioRoomCell.h"
namespace aspirant
{
	nlohmann::json ScenarioRoomCell::CellFlagToJSON(const ScenarioRoomCellFlags& cellFlag)
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

		throw "NOT IMPLEMENTED";
	}

	bool ScenarioRoomCell::CanCover(const ScenarioObjectInstance* newObject, const ScenarioObjectInstance* oldObject) const
	{
		return newObject->CanCover(oldObject);
	}

}