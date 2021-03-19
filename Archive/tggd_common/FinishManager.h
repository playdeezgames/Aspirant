#pragma once
#include <set>
#include "Finisher.h"
namespace tggd::common
{
	class FinishManager
	{
		FinishManager(const FinishManager&) = delete;
		FinishManager(FinishManager&&) = delete;
		FinishManager& operator=(const FinishManager&) = delete;
		FinishManager& operator=(FinishManager&&) = delete;
	private:
		std::set<Finisher*> finishers;
	public:
		FinishManager();
		void Add(Finisher*);
		void Finish();
	};
}

