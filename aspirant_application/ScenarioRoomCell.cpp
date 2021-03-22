#include "ScenarioRoomCell.h"
#include "DescriptorManager.h"
namespace aspirant::game
{
	const std::string PROPERTY_TYPE = "type";

	ScenarioObjectInstance* ScenarioRoomCell::ObjectFromJSON(const nlohmann::json& properties)
	{
		auto obj = DescriptorManager::Get(properties[PROPERTY_TYPE])->CreateObject();
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