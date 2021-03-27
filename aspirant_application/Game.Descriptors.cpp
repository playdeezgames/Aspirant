#include "Game.Descriptors.h"
#include "Common.Finishers.h"
#include <map>
#include "Common.Finisher.h"
#include "Data.JSON.h"
#include "Game.Properties.h"
#include "Game.Types.h"
namespace game::Descriptors
{
	static nlohmann::json table;
	static std::vector<std::string> identifiers;

	const std::vector<std::string>& GetIdentifiers()
	{
		return identifiers;
	}

	void Start(const std::string& filename)
	{
		table = data::JSON::Load(filename);
		for (auto& item : table.items())
		{
			auto identifier = item.key();
			identifiers.push_back(item.key());
		}
	}

	game::descriptor::Common Get(const std::string& key)
	{
		return game::descriptor::Common(key, table[key]);
	}


}