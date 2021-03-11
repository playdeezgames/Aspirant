#pragma once
#include "EditorMenuStateHandler.h"
#include "Command.h"
#include "EditorContext.h"
namespace aspirant
{
	enum class NewRoomItem
	{
		NAME,
		COLUMNS,
		ROWS,
		CREATE,
		CANCEL
	};
	class EditNewRoomStateHandler : public EditorMenuStateHandler<NewRoomItem>
	{
	private:
		void CreateRoom();
	protected:
		bool OnCommand(const aspirant::commonui::Command& command);
		bool OnUpdate();
		bool OnText(const std::string&);
		void ActivateItem(const NewRoomItem&);
		void IncreaseItem(const NewRoomItem&);
		void DecreaseItem(const NewRoomItem&);
	public:
		EditNewRoomStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const aspirant::commonui::UIContext&
		);
	};
}
