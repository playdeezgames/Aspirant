#include "FinishManager.h"
namespace tggd::common
{
	FinishManager::FinishManager()
		: finishers()
	{

	}

	void FinishManager::Add(Finisher* finisher)
	{
		finishers.insert(finisher);
	}

	void FinishManager::Finish()
	{
		for (auto finisher : finishers)
		{
			finisher->Finish();
		}
		finishers.clear();
	}
}

