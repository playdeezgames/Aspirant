#include "Game.Cell.h"
#include "Game.Descriptors.h"
#include "Game.Properties.h"
namespace game
{
	Cell::Cell(nlohmann::json& model, size_t column, size_t row)
		: model(model)
		, column(column)
		, row(row)
	{

	}

	game::object::Common Cell::AddObject(const game::descriptor::Common& descriptor)
	{
		model[game::Properties::OBJECTS].push_back(nlohmann::json());
		return descriptor.CreateObject(model[game::Properties::OBJECTS].back());
	}

	std::vector<game::object::Common> Cell::GetObjects() const
	{
		std::vector<game::object::Common> result;
		for (auto& obj : model[game::Properties::OBJECTS])
		{
			result.push_back(game::object::Common(obj));
		}
		return result;
	}

	bool Cell::HasObjects() const
	{
		return !model.empty();
	}

	size_t Cell::GetColumn() const
	{
		return column;
	}

	size_t Cell::GetRow() const
	{
		return row;
	}

	bool Cell::RemoveObject()
	{
		if (model[game::Properties::OBJECTS].empty())
		{
			return false;
		}
		else
		{
			model[game::Properties::OBJECTS].erase(model[game::Properties::OBJECTS].size() - 1);
			return true;
		}
	}

	std::optional<game::object::Common> Cell::GetObject() const
	{
		if (model[game::Properties::OBJECTS].empty())
		{
			return std::optional<game::object::Common>();
		}
		else
		{
			return std::optional<game::object::Common>(model[game::Properties::OBJECTS].back());
		}
	}


}