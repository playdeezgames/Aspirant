#pragma once
#include "BaseDescriptor.h"
#include "ScenarioObjectInstance.h"
namespace aspirant::game
{
	class CommonDescriptor : public aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>
	{
	private:
		const std::string PROPERTY_SPRITE = "sprite";
		std::string sprite;
	public:
		CommonDescriptor(const std::string& name, const nlohmann::json& properties)
			: aspirant::game::BaseDescriptor<aspirant::game::ScenarioObjectInstance>(name, properties)
			, sprite(properties[PROPERTY_SPRITE])
		{

		}
		const std::string& GetSprite() const
		{
			return sprite;
		}
	};
}
