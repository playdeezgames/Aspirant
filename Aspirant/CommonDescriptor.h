#pragma once
#include "BaseDescriptor.h"
#include "ScenarioObjectInstance.h"
namespace aspirant
{
	class CommonDescriptor : public BaseDescriptor<ScenarioObjectInstance>
	{
	private:
		const std::string PROPERTY_SPRITE = "sprite";
		std::string sprite;
	public:
		CommonDescriptor(const std::string& name, const nlohmann::json& properties)
			: BaseDescriptor(name, properties)
			, sprite(properties[PROPERTY_SPRITE])
		{

		}
		const std::string& GetSprite() const
		{
			return sprite;
		}
	};
}
