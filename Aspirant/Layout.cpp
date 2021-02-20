#include "Layout.h"
#include "Utility.h"
namespace tggd::common
{
	Layout::Layout(FinishManager& finishManager)
		: drawnItems()
	{
		finishManager.Add(this);
	}

	void Layout::Draw(SDL_Renderer* renderer) const
	{
		for (auto& item : drawnItems)
		{
			item->Draw(renderer);
		}
	}

	void Layout::Finish()
	{
		for (auto& item : drawnItems)
		{
			Utility::SafeDelete(item);
		}
		drawnItems.clear();
	}

	void Layout::Add(Drawn* drawn)
	{
		drawnItems.remove(drawn);
		drawnItems.push_back(drawn);
	}
}