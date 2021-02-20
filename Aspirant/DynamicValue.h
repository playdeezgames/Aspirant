#pragma once
#include "IValue.h"
#include "IDataStore.h"
namespace tggd::common
{
	template<typename TValue>
	class DynamicValue : public IValue<TValue>
	{
	private:
		const IDataStore<TValue>& store;
		std::string key;
	public:
		DynamicValue(const IDataStore<TValue>& store, const std::string& key)
			: store(store)
			, key(key)
		{

		}
		const TValue& Get() const
		{
			return store.Get(key);
		}
	};
}
