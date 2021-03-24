#pragma once
#include <string>
template<typename TMenuItem>
class MenuItem
{
private:
	TMenuItem nextMenuItem;
	TMenuItem previousMenuItem;
	std::string itemColorName;
public:
	MenuItem() = default;
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
	const TMenuItem& GetNextMenuItem() const
	{
		return nextMenuItem;
	}
	const TMenuItem& GetPreviousMenuItem() const
	{
		return previousMenuItem;
	}
	const std::string& GetItemColorName() const
	{
		return itemColorName;
	}
};

