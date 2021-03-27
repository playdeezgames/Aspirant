#include "Game.Avatar.h"
#include "Common.Properties.h"
namespace game
{
	const std::string PROPERTY_ROOM = "room";

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
		model[common::Properties::X] = xy.GetX();
		model[common::Properties::Y] = xy.GetY();
	}

	common::XY<size_t> Avatar::GetPosition() const
	{
		return common::XY<size_t>(model[common::Properties::X], model[common::Properties::Y]);
	}
}