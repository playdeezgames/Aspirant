#pragma once
namespace tggd::data
{
	template<typename TValue>
	class IValue
	{
	protected:
		virtual const TValue& Get() const = 0;
	public:
		const TValue& operator*() const
		{
			return Get();
		}
	};
}
