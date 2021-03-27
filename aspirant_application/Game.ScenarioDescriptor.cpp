#pragma once
#include "Game.ScenarioDescriptor.h"
#include "Common.Properties.h"
#include "Game.Properties.h"
namespace game
{
	ScenarioDescriptor::ScenarioDescriptor(nlohmann::json& model)
		: model(model)
	{

	}

	int ScenarioDescriptor::GetId() const
	{
		return model[game::Properties::ID];
	}

	void ScenarioDescriptor::SetName(const std::string& newName)
	{
		model[common::Properties::NAME] = newName;
	}

	std::string ScenarioDescriptor::GetName() const
	{
		return model[common::Properties::NAME];
	}

	void ScenarioDescriptor::SetBrief(const std::string newBrief)
	{
		model[game::Properties::BRIEF] = newBrief;
	}

	std::string ScenarioDescriptor::GetBrief() const
	{
		return model[game::Properties::BRIEF];
	}

	std::string ScenarioDescriptor::GetFileName() const
	{
		return model[game::Properties::FILE_NAME];
	}
}
