#pragma once
#include <string>
#include "json.hpp"
namespace game
{
	class ScenarioDescriptor
	{
	private:
		const std::string PROPERTY_NAME = "name";
		const std::string PROPERTY_BRIEF = "brief";
		const std::string PROPERTY_FILE_NAME = "fileName";
		const std::string PROPERTY_ID = "id";
		nlohmann::json& model;
	public:
		ScenarioDescriptor(nlohmann::json& model)
			: model(model)
		{

		}
		int GetId() const
		{
			return model[PROPERTY_ID];
		}
		void SetName(const std::string& newName)
		{
			model[PROPERTY_NAME] = newName;
		}
		std::string GetName() const
		{
			return model[PROPERTY_NAME];
		}
		void SetBrief(const std::string newBrief)
		{
			model[PROPERTY_BRIEF] = newBrief;
		}
		std::string GetBrief() const
		{
			return model[PROPERTY_BRIEF];
		}
		std::string GetFileName() const
		{
			return model[PROPERTY_FILE_NAME];
		}
	};
}
