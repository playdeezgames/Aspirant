#pragma once
namespace tggd::data
{
	template<typename TValue>
	class IValue
	{
	public:
		virtual const TValue& Get() const = 0;
		const TValue& operator*() const
		{
			return Get();
		}
	};
}
