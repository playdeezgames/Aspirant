#include "Game.Cell.h"
#include "Game.Descriptors.h"
namespace game
{
	const std::string PROPERTY_OBJECTS = "objects";

	Cell::Cell(nlohmann::json& model, size_t column, size_t row)
		: model(model)
		, column(column)
		, row(row)
	{

	}

	game::object::Common Cell::AddObject()
	{
		model.push_back(nlohmann::json());
		return game::object::Common(model.back());
	}

	std::vector<game::object::Common> Cell::GetObjects() const
	{
		std::vector<game::object::Common> result;
		for (auto& obj : model[PROPERTY_OBJECTS])
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
		if (model.empty())
		{
			return false;
		}
		else
		{
			model.erase(model.size() - 1);
			return true;
		}
	}

}