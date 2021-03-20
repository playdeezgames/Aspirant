#include "FinishManager.h"
#include <set>
namespace tggd::common::FinishManager
{
	static std::set<Finisher> finishers;

	void Add(Finisher finisher)
	{
		finishers.insert(finisher);
	}

	void Finish()
	{
		for (auto finisher : finishers)
		{
			finisher();
		}
		finishers.clear();
	}
}

