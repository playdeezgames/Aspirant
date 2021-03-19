#pragma once
#include <string>
namespace aspirant::commonui
{
	template<typename TMenuItem>
	class MenuItemDescriptor
	{
		MenuItemDescriptor(MenuItemDescriptor&&) = delete;
		MenuItemDescriptor& operator=(MenuItemDescriptor&&) = delete;
	private:
		TMenuItem nextMenuItem;
		TMenuItem previousMenuItem;
		std::string itemColorName;
	public:
		MenuItemDescriptor() = default;
		MenuItemDescriptor(const MenuItemDescriptor&) = default;
		MenuItemDescriptor& operator=(const MenuItemDescriptor&) = default;
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
