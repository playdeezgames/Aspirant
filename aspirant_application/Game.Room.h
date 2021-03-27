#pragma once
#include "Game.Cell.h"
namespace game
{
	class Room
	{
	private:
		nlohmann::json& model;
	public:
		void SetSize(size_t, size_t);
		Room(nlohmann::json&);
		Cell GetCell(size_t, size_t);
		size_t GetColumns() const;
		size_t GetRows() const;
	};
}
