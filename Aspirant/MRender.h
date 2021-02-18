#pragma once
#include "MGeneric.h"
#include "Renderer.h"
#include <SDL.h>
namespace tggd::common
{
	class MRender : public MGeneric
	{
	private:
		SDL_Renderer* _renderer;
	public:
		MRender(SDL_Renderer* renderer)
			: MGeneric(Renderer::MSGID_Draw)
			, _renderer(renderer)
		{

		}
		SDL_Renderer* GetRenderer() const
		{
			return _renderer;
		}
	};
}
