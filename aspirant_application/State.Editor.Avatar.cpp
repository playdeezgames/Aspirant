#include "State.Editor.Avatar.h"
#include <string>
#include <SDL.h>
#include "UIState.h"
#include "Graphics.Layouts.h"
#include "Command.h"
#include "Application.h"
#include <map>
#include "MenuItem.h"
#include "Context.Editor.Scenario.h"
#include "Data.Strings.h"
#include <sstream>
namespace state::editor::Avatar
{
	const std::string LAYOUT_NAME = "EditAvatar";
	const std::string COLOR_ROOM_NAME = "EditAvatar.Color.RoomName";
	const std::string COLOR_COLUMN = "EditAvatar.Color.Column";
	const std::string COLOR_ROW = "EditAvatar.Color.Row";
	const std::string COLOR_BACK = "EditAvatar.Color.Back";
	const std::string TEXT_ROOM_NAME = "EditAvatar.Text.RoomName";
	const std::string TEXT_COLUMN = "EditAvatar.Text.Column";
	const std::string TEXT_ROW = "EditAvatar.Text.Row";

	enum class AvatarMenuItem
	{
		ROOM_NAME,
		COLUMN,
		ROW,
		BACK
	};
	static AvatarMenuItem current = AvatarMenuItem::BACK;
	static std::map<AvatarMenuItem, MenuItem<AvatarMenuItem>> items =
	{
		{AvatarMenuItem::ROOM_NAME, MenuItem<AvatarMenuItem>(COLOR_ROOM_NAME, AvatarMenuItem::BACK, AvatarMenuItem::COLUMN)},
		{AvatarMenuItem::COLUMN, MenuItem<AvatarMenuItem>(COLOR_COLUMN, AvatarMenuItem::ROOM_NAME, AvatarMenuItem::ROW)},
		{AvatarMenuItem::ROW, MenuItem<AvatarMenuItem>(COLOR_ROW, AvatarMenuItem::COLUMN, AvatarMenuItem::BACK)},
		{AvatarMenuItem::BACK, MenuItem<AvatarMenuItem>(COLOR_BACK, AvatarMenuItem::ROW, AvatarMenuItem::ROOM_NAME)}
	};

	static void MovePositionBy(const common::XY<int>& delta)
	{
		auto position = context::editor::Scenario::Get().GetAvatar().GetPosition();
		position = common::XY<size_t>(position.GetX() + delta.GetX(), position.GetY() + delta.GetY());
		context::editor::Scenario::Get().GetAvatar().SetPosition(position);
	}

	static void DecreaseItem()
	{
		switch (current)
		{
		case AvatarMenuItem::COLUMN:
			MovePositionBy({ -1, 0 });
			break;
		case AvatarMenuItem::ROW:
			MovePositionBy({ 0, -1 });
			break;
		}
	}

	static void IncreaseItem()
	{
		switch (current)
		{
		case AvatarMenuItem::COLUMN:
			MovePositionBy({ 1, 0 });
			break;
		case AvatarMenuItem::ROW:
			MovePositionBy({ 0, 1 });
			break;
		}
	}

	static void ActivateItem()
	{
		if(current==AvatarMenuItem::BACK)
		{
			context::editor::Scenario::Save();
			Application::SetUIState(UIState::EDIT_SCENARIO);
		}
	}


	static void OnCommand(const ::Command& command)
	{
		switch (command)
		{
		case Command::BACK:
			if (current == AvatarMenuItem::ROOM_NAME)
			{
				auto avatar = context::editor::Scenario::Get().GetAvatar();
				std::string value = avatar.GetRoomId();
				if (!value.empty())
				{
					value.pop_back();
				}
				avatar.SetRoomId(value);
			}
			else
			{
				context::editor::Scenario::Save();
				Application::SetUIState(UIState::EDIT_SCENARIO);
			}
			break;
		case Command::UP:
			MenuItem<AvatarMenuItem>::Previous(current, items);
			break;
		case Command::DOWN:
			MenuItem<AvatarMenuItem>::Next(current, items);
			break;
		case Command::LEFT:
			DecreaseItem();
			break;
		case Command::RIGHT:
			IncreaseItem();
			break;
		case Command::GREEN:
			ActivateItem();
			break;
		}
	}

	static void OnUpdate(const Uint32& ticks)
	{
		auto avatar = context::editor::Scenario::Get().GetAvatar();

		MenuItem<AvatarMenuItem>::Update(items, current);
		data::Strings::Set(TEXT_ROOM_NAME, avatar.GetRoomId());

		std::stringstream ss;
		ss << avatar.GetPosition().GetX();
		data::Strings::Set(TEXT_COLUMN, ss.str());

		ss.str("");
		ss << avatar.GetPosition().GetY();
		data::Strings::Set(TEXT_ROW, ss.str());
	}

	static void OnTextInput(const std::string& text)
	{
		if (current == AvatarMenuItem::ROOM_NAME)
		{
			auto avatar = context::editor::Scenario::Get().GetAvatar();
			avatar.SetRoomId(avatar.GetRoomId() + text);
		}
	}

	void Start()
	{
		Application::SetCommandHandler(UIState::EDIT_AVATAR, OnCommand);
		Application::SetRenderLayout(UIState::EDIT_AVATAR, LAYOUT_NAME);
		Application::SetUpdateHandler(UIState::EDIT_AVATAR, OnUpdate);
		Application::SetTextInputHandler(UIState::EDIT_AVATAR, OnTextInput);
	}
}
