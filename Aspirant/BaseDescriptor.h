#pragma once
#include <string>
#include "json.hpp"
namespace aspirant
{
	template<typename TInstance>
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
		virtual TInstance* CreateObject() const = 0;
	};
}
