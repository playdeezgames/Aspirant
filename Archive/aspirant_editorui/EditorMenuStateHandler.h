#pragma once
#include "MenuStateHandler.h"
#include "EditorContextClient.h"
namespace aspirant::editorui
{
	template<typename TMenuItem>
	class EditorMenuStateHandler : public aspirant::commonui::MenuStateHandler<TMenuItem>, public EditorContextClient
	{
	public:
		EditorMenuStateHandler
		(
			tggd::common::MessageHandler* parent,
			const aspirant::commonui::UIState& filterState,
			const aspirant::commonui::UIState& parentState,
			const std::string& layoutName,
			const TMenuItem& menuItem,
			const aspirant::commonui::UIContext& uiContext,
			aspirant::editor::context::EditorContext& editorContext
		)
			: aspirant::commonui::MenuStateHandler<TMenuItem>(parent, filterState, parentState, layoutName, menuItem, uiContext)
			, EditorContextClient(editorContext)
		{

		}

	};
}