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
		static void MSGID_Draw() {}
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
		static bool Is(const MGeneric* message)
		{
			return message && message->GetId() == MSGID_Draw;
		}
		static const MRender* From(const MGeneric* message)
		{
			return static_cast<const tggd::common::MRender*>(message);
		}
	};
}
