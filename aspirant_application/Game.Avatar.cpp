#include "Game.Avatar.h"
namespace game
{
	const std::string PROPERTY_ROOM = "room";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";

	void Avatar::SetRoomId(const std::string& id)
	{
		model[PROPERTY_ROOM] = id;
	}

	std::string Avatar::GetRoomId() const
	{
		return model[PROPERTY_ROOM];
	}

	void Avatar::SetPosition(const common::XY<size_t> xy)
	{
		model[PROPERTY_X] = xy.GetX();
		model[PROPERTY_Y] = xy.GetY();
	}

	common::XY<size_t> Avatar::GetPosition() const
	{
		return common::XY<size_t>(model[PROPERTY_X], model[PROPERTY_Y]);
	}
}