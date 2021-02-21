#pragma once
#include <string>
#include <set>
#include "IDataStore.h"
namespace tggd::common
{
	class FlagManager : public IDataStore<bool>
	{
	private:
		std::set<std::string> flags;
	public:
		FlagManager();
		void Start(const std::string&);
		const bool& Get(const std::string&) const;
		void Set(const std::string&);
		void Clear(const std::string&);
		void Toggle(const std::string&);
	};
}
