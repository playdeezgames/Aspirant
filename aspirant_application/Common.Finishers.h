#pragma once
#include <set>
namespace common::Finishers
{
	typedef void(*Finisher)();
	void Add(Finisher);
	void Finish();
}

