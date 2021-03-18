#pragma once
#include "IValue.h"
#include "IDataStore.h"
namespace tggd::data
{
	template<typename TValue>
	class DynamicValue : public IValue<TValue>
	{
		DynamicValue() = delete;
		DynamicValue(const DynamicValue&) = delete;
		DynamicValue(DynamicValue&&) = delete;
		DynamicValue& operator=(const DynamicValue&) = delete;
		DynamicValue& operator=(DynamicValue&&) = delete;
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
