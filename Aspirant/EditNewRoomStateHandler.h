#pragma once
#include "MenuStateHandler.h"
#include <SDL.h>
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
	class EditNewRoomStateHandler : public MenuStateHandler<NewRoomItem>
	{
	private:
		EditorContext& editorContext;
	protected:
		bool OnText(const std::string&);
		void ActivateItem(const NewRoomItem&);
		void IncreaseItem(const NewRoomItem&);
		void DecreaseItem(const NewRoomItem&);
	public:
		EditNewRoomStateHandler
		(
			MessageHandler*,
			EditorContext&,
			const UIContext&
		);
	};
}
