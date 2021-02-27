#pragma once
#include <string>
#include "json.hpp"
#include "BaseGameObject.h"
namespace aspirant
{
	class BaseDescriptor
	{
	private:
		const std::string PROPERTY_TYPE = "type";
		std::string descriptorType;
	public:
		BaseDescriptor(const nlohmann::json& properties)
			: descriptorType(properties[PROPERTY_TYPE])
		{
		}
		virtual ~BaseDescriptor(){}
		const std::string& GetType() const
		{
			return descriptorType;
		}
		virtual BaseGameObject* LoadGameObject(const nlohmann::json&) const = 0;
		virtual BaseGameObject* NewGameObject() const = 0;
	};
}
