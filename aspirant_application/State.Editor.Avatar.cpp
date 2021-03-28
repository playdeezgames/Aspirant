#include "Application.h"
#include "Graphics.Layouts.h"
#include "Common.XY.h"
#include "Context.Editor.Scenario.h"
#include "Data.Strings.h"
#include <sstream>
namespace state::editor::Avatar
{
	const std::string LAYOUT_NAME = "State.Editor.Avatar";
	const std::string MENU_ID = "Avatar";
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

	static void MovePositionBy(const common::XY<int>& delta)
	{
		auto position = context::editor::Scenario::Get().GetAvatar().GetPosition();
		position = common::XY<size_t>(position.GetX() + delta.GetX(), position.GetY() + delta.GetY());
		context::editor::Scenario::Get().GetAvatar().SetPosition(position);
	}

	static AvatarMenuItem GetCurrentItem()
	{
		return (AvatarMenuItem)graphics::Layouts::GetMenuValue(LAYOUT_NAME, MENU_ID).value();
	}

	static void DecreaseItem()
	{
		switch (GetCurrentItem())
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
		switch (GetCurrentItem())
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
		if(GetCurrentItem()==AvatarMenuItem::BACK)
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
			if (GetCurrentItem() == AvatarMenuItem::ROOM_NAME)
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
			graphics::Layouts::PreviousMenuIndex(LAYOUT_NAME, MENU_ID);
			break;
		case Command::DOWN:
			graphics::Layouts::NextMenuIndex(LAYOUT_NAME, MENU_ID);
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
		if (GetCurrentItem() == AvatarMenuItem::ROOM_NAME)
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