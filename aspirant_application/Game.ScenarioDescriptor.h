#pragma once
#include <string>
#include "json.hpp"
namespace game
{
	class ScenarioDescriptor
	{
	private:
		nlohmann::json& model;
	public:
		ScenarioDescriptor(nlohmann::json& model);
		int GetId() const;
		void SetName(const std::string& newName);
		std::string GetName() const;
		void SetBrief(const std::string newBrief);
		std::string GetBrief() const;
		std::string GetFileName() const;
	};
}
