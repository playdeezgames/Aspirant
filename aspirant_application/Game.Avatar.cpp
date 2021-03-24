#include "Game.Avatar.h"
namespace game
{
	void Avatar::SetRoomId(const std::string& id)
	{
		roomId = id;
	}

	const std::string& Avatar::GetRoomId() const
	{
		return roomId;
	}

	void Avatar::SetPosition(const common::XY<size_t> xy)
	{
		position = xy;
	}

	const common::XY<size_t> Avatar::GetPosition() const
	{
		return position;
	}

	const std::string PROPERTY_ROOM = "room";
	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";

	void Avatar::FromJSON(const nlohmann::json& properties)
	{
		SetRoomId(properties[PROPERTY_ROOM]);
		SetPosition(common::XY<size_t>(properties[PROPERTY_X], properties[PROPERTY_Y]));
	}

	nlohmann::json Avatar::ToJSON() const
	{
		nlohmann::json properties;
		properties[PROPERTY_ROOM] = GetRoomId();
		properties[PROPERTY_X] = GetPosition().GetX();
		properties[PROPERTY_Y] = GetPosition().GetY();
		return properties;
	}

}