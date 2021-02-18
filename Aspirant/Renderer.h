#pragma once
#include <SDL.h>
namespace tggd::common
{
	class Renderer
	{
	protected:
		virtual void OnRender(SDL_Renderer*) const = 0;
	public:
		static void MSGID_Draw() {}
	};
}
