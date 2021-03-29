#include "Game.ScenarioDescriptors.h"
#include "Common.Utility.h"
#include "Data.JSON.h"
#include "Common.Finisher.h"
#include <sstream>
#include "Common.Properties.h"
#include "Game.Properties.h"
namespace game::ScenarioDescriptors
{
	static nlohmann::json table;
	static std::string fileName;

	void Load(const std::string& filename)
	{
		fileName = filename;
		table = data::JSON::Load(fileName);
	}

	void Save()
	{
		data::JSON::Save(fileName, table);
	}

	int GetNextId()
	{
		int maximum = 0;
		for (auto& item : table)
		{
			auto descriptor = game::ScenarioDescriptor(item);
			maximum = (descriptor.GetId() > maximum) ? (descriptor.GetId()) : (maximum);
		}
		return maximum + 1;
	}

	const std::string SCENARIO_FILE_PREFIX = "scenarios/scenario_";
	const std::string SCENARIO_FILE_SUFFIX = ".json";
	const std::string DEFAULT_SCENARIO_NAME = "New Scenario";
	const std::string DEFAULT_SCENARIO_BRIEF = "The best scenario ever!";

	size_t Add()
	{
		auto scenarioId = GetNextId();
		std::stringstream ss;
		ss << SCENARIO_FILE_PREFIX << scenarioId << SCENARIO_FILE_SUFFIX;
		size_t index = table.size();
		auto item = nlohmann::json();
		item[game::Properties::ID] = scenarioId;
		item[common::Properties::NAME] = DEFAULT_SCENARIO_NAME;
		item[game::Properties::BRIEF] = DEFAULT_SCENARIO_BRIEF;
		item[game::Properties::FILE_NAME] = ss.str();
		table.push_back(item);
		Save();
		return index;
	}

	size_t GetCount()
	{
		return table.size();
	}

	std::optional<game::ScenarioDescriptor> Get(size_t index)
	{
		if (table.size()>index)
		{
			return std::optional<game::ScenarioDescriptor>(game::ScenarioDescriptor(table[index]));
		}
		else
		{
			return std::optional<game::ScenarioDescriptor>();
		}
	}
}