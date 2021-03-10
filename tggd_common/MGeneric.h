#pragma once
namespace tggd::common
{
	typedef void(*messageid_t)();
	class MGeneric
	{
	private:
		messageid_t messageId;
	public:
		MGeneric(messageid_t messageId)
			: messageId(messageId)
		{

		}
		messageid_t GetId() const
		{
			return messageId;
		}
	};
}
