#pragma once
namespace tggd::common
{
	typedef void(*messageid_t)();
	class MGeneric
	{
	private:
		messageid_t messageId;
	protected:
		bool HasId(const messageid_t& messageId)
		{
			return this && GetId() == messageId;
		}
	public:
		MGeneric(const messageid_t& messageId)
			: messageId(messageId)
		{

		}
		const messageid_t& GetId() const
		{
			return messageId;
		}
	};
}
