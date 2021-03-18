#pragma once
#include "IValue.h"
namespace tggd::data
{
	template<typename TValue>
	class ConstantValue : public IValue<TValue>
	{
		ConstantValue() = delete;
		ConstantValue(const ConstantValue&) = delete;
		ConstantValue(ConstantValue&&) = delete;
		ConstantValue& operator=(const ConstantValue&) = delete;
		ConstantValue& operator=(ConstantValue&&) = delete;
	private:
		TValue value;
	public:
		ConstantValue(const TValue& value)
			: value(value)
		{

		}
		const TValue& Get() const
		{
			return value;
		}
	};
}
