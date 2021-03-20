#include "CreatureDescriptor.h"
#include "CreatureInstance.h"
namespace aspirant::game
{
	CreatureDescriptor::CreatureDescriptor(const std::string& name, const nlohmann::json& properties)
		: CommonDescriptor(name, properties)
	{

	}

	ScenarioObjectInstance* CreatureDescriptor::CreateObject() const
	{
		return new CreatureInstance(*this);
	}

}