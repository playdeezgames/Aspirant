#pragma once
#include "IValue.h"
namespace tggd::common
{
	template<typename TValue>
	class ConstantValue : public IValue<TValue>
	{
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
