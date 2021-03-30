#include "Application.UIState.h"
namespace application::UIState
{
	static ::UIState uiState = ::UIState::SPLASH;

	void SetUIState(const ::UIState& state)
	{
		uiState = state;
	}

	const ::UIState& GetUIState()
	{
		return uiState;
	}
}