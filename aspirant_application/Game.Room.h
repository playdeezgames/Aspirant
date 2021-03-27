#pragma once
#include "Game.Cell.h"
#include <optional>
namespace game
{
	class Room
	{
	private:
		nlohmann::json& model;
	public:
		void SetSize(size_t, size_t);
		Room(nlohmann::json&);
		std::optional<Cell> GetCell(size_t, size_t);
		size_t GetColumns() const;
		size_t GetRows() const;
	};
}
