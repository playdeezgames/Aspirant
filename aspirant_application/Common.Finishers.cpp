#include "Common.Finishers.h"
#include <set>
namespace common::Finishers
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

