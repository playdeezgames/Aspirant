#pragma once
#include <set>
namespace tggd::common::FinishManager
{
	typedef void(*Finisher)();
	void Add(Finisher);
	void Finish();
}

