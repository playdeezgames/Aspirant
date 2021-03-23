#pragma once
#include <string>
#include "json.hpp"
namespace game::object
{
	class Common;
}
namespace game::descriptor
{
	class Common
	{
	private:
		const std::string PROPERTY_TYPE = "type";
		const std::string PROPERTY_SPRITE = "sprite";
		std::string descriptorType;
		std::string name;
		std::string sprite;
	public:
		Common(const std::string& name, const nlohmann::json& properties)
			: descriptorType(properties[PROPERTY_TYPE])
			, name(name)
			, sprite(properties[PROPERTY_SPRITE])
		{
		}
		const std::string& GetType() const
		{
			return descriptorType;
		}
		const std::string& GetName() const
		{
			return name;
		}
		virtual game::object::Common* CreateObject() const = 0;
		const std::string& GetSprite() const
		{
			return sprite;
		}
	};
}
