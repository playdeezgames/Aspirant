#include "Game.Avatar.h"
#include "Common.Properties.h"
#include "Game.Properties.h"
namespace game
{
	void Avatar::SetRoomId(const std::string& id)
	{
		model[game::Properties::ROOM] = id;
	}

	std::string Avatar::GetRoomId() const
	{
		return model[game::Properties::ROOM];
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