#pragma once
#include "MenuStateHandler.h"
#include "EditorContextClient.h"
namespace aspirant
{
	template<typename TMenuItem>
	class EditorMenuStateHandler : public MenuStateHandler<TMenuItem>, public EditorContextClient
	{
	public:
		EditorMenuStateHandler
		(
			tggd::common::MessageHandler* parent,
			const UIState& filterState,
			const UIState& parentState,
			const std::string& layoutName,
			const TMenuItem& menuItem,
			const UIContext& uiContext,
			EditorContext& editorContext
		)
			: MenuStateHandler<TMenuItem>(parent, filterState, parentState, layoutName, menuItem, uiContext)
			, EditorContextClient(editorContext)
		{

		}

	};
}