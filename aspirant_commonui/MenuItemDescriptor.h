#pragma once
#include <string>
namespace aspirant::commonui
{
	template<typename TMenuItem>
	class MenuItemDescriptor
	{
	private:
		TMenuItem nextMenuItem;
		TMenuItem previousMenuItem;
		std::string itemColorName;
	public:
		MenuItemDescriptor() :nextMenuItem(), previousMenuItem(), itemColorName() {}//MAGIC!
		MenuItemDescriptor
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
}
