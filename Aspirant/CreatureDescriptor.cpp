#include "CreatureDescriptor.h"
#include "CreatureInstance.h"
namespace aspirant
{
	CreatureDescriptor::CreatureDescriptor(const nlohmann::json& properties)
		: BaseDescriptor(properties)
	{

	}

	ScenarioObjectInstance* CreatureDescriptor::CreateObject() const
	{
		return new CreatureInstance(*this);
	}
}