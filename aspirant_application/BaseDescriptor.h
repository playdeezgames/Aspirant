#pragma once
#include <string>
#include "json.hpp"
namespace aspirant::game
{
	template<typename TInstance>
	class BaseDescriptor
	{
	private:
		const std::string PROPERTY_TYPE = "type";
		std::string descriptorType;
		std::string name;
	public:
		BaseDescriptor(const std::string& name, const nlohmann::json& properties)
			: descriptorType(properties[PROPERTY_TYPE])
			, name(name)
		{
		}
		virtual ~BaseDescriptor() {}
		const std::string& GetType() const
		{
			return descriptorType;
		}
		const std::string& GetName() const
		{
			return name;
		}
		virtual TInstance* CreateObject() const = 0;
	};
}
