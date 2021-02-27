#pragma once
#include <string>
#include "json.hpp"
namespace aspirant
{
	class ScenarioDescriptor
	{
	private:
		const std::string PROPERTY_NAME = "name";
		const std::string PROPERTY_BRIEF = "brief";
		const std::string PROPERTY_FILE_NAME = "fileName";
		std::string name;
		std::string brief;
		std::string fileName;
	public:
		ScenarioDescriptor(const nlohmann::json& properties)
			: name(properties[PROPERTY_NAME])
			, brief(properties[PROPERTY_BRIEF])
			, fileName(properties[PROPERTY_FILE_NAME])
		{

		}
		const std::string& GetName() const
		{
			return name;
		}
		const std::string& GetBrief() const
		{
			return brief;
		}
		const std::string& GetFileName() const
		{
			return fileName;
		}
	};
}
