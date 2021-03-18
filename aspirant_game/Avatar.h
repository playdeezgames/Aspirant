#pragma once
#include <string>
#include "XY.h"
namespace aspirant::game
{
	class Avatar
	{
	private:
		std::string roomName;
		tggd::common::XY<size_t> position;
	public:
		const std::string GetRoomName() const
		{
			return roomName;
		}
		const tggd::common::XY<size_t> GetPosition() const
		{

		}
	};
}
