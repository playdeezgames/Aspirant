#pragma once
#include <string>
#include <map>
#include "Data.Strings.h"
template<typename TMenuItem>
class MenuItem
{
private:
	TMenuItem nextMenuItem;
	TMenuItem previousMenuItem;
	std::string itemColorName;
public:
	MenuItem() :nextMenuItem(), previousMenuItem(), itemColorName() {}
	MenuItem(const MenuItem&) = default;
	MenuItem& operator=(const MenuItem&) = default;
	MenuItem(MenuItem&&) = default;
	MenuItem& operator=(MenuItem&&) = default;
	MenuItem
	(
		const std::string& itemColorName,
		const TMenuItem& previousMenuItem,
		const TMenuItem& nextMenuItem
	)
		: nextMenuItem(nextMenuItem)
		, previousMenuItem(previousMenuItem)
		, itemColorName(itemColorName)
	{

	}
	static void Update(const std::map<TMenuItem, MenuItem<TMenuItem>>& items, const TMenuItem& current)
	{
		for (auto& item : items)
		{
			::data::Strings::Set(item.second.itemColorName, (item.first == current) ? ("Cyan") : ("Gray"));
		}
	}
	static void Next(TMenuItem& current, const std::map<TMenuItem, MenuItem<TMenuItem>>& items)
	{
		current = items.find(current)->second.nextMenuItem;
	}
	static void Previous(TMenuItem& current, const std::map<TMenuItem, MenuItem<TMenuItem>>& items)
	{
		current = items.find(current)->second.previousMenuItem;
	}
};

