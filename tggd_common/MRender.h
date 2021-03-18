#pragma once
#include "MGeneric.h"
#include <SDL.h>
namespace tggd::common
{
	class MRender : public MGeneric
	{
		MRender() = delete;
		MRender(const MRender&) = delete;
		MRender(MRender&&) = delete;
		MRender& operator=(const MRender&) = delete;
		MRender& operator=(MRender&&) = delete;
	private:
		SDL_Renderer* _renderer;
	public:
		MRender(SDL_Renderer* renderer)
			: MGeneric(MSGID_Draw)
			, _renderer(renderer)
		{

		}
		SDL_Renderer* GetRenderer() const
		{
			return _renderer;
		}
		static void MSGID_Draw() {}
	};
}
