#pragma once
namespace tggd::common
{
	template<typename TValue>
	class IValue
	{
	public:
		virtual const TValue& Get() const = 0;
	};
}
