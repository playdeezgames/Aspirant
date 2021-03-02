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
		const std::string PROPERTY_ID = "id";
		int id;
		std::string name;
		std::string brief;
		std::string fileName;
	public:
		ScenarioDescriptor(const nlohmann::json& properties)
			: name(properties[PROPERTY_NAME])
			, brief(properties[PROPERTY_BRIEF])
			, fileName(properties[PROPERTY_FILE_NAME])
			, id(properties[PROPERTY_ID])
		{

		}
		ScenarioDescriptor
		(
			int id, 
			const std::string& name, 
			const std::string& brief, 
			const std::string& fileName
		)
			: id(id)
			, name(name)
			, brief(brief)
			, fileName(fileName)
		{

		}
		int GetId() const
		{
			return id;
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
		nlohmann::json ToJSON() const
		{
			nlohmann::json properties;
			properties[PROPERTY_ID] = GetId();
			properties[PROPERTY_BRIEF] = GetBrief();
			properties[PROPERTY_NAME] = GetName();
			properties[PROPERTY_FILE_NAME] = GetFileName();
			return properties;
		}
	};
}
