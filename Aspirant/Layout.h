#pragma once
#include "Drawn.h"
#include "FinishManager.h"
#include <list>
namespace tggd::common
{
	class Layout: public Drawn, public Finisher
	{
	private:
		std::list<Drawn*> drawnItems;
	public:
		Layout(FinishManager&);
		void Draw(SDL_Renderer*) const;
		void Finish();
		void Add(Drawn*);
	};
}
