#pragma once
#include "MGeneric.h"
namespace tggd::common
{
	class MUpdate : public MGeneric
	{
		MUpdate() = delete;
		MUpdate(const MUpdate&) = delete;
		MUpdate(MUpdate&&) = delete;
		MUpdate& operator=(const MUpdate&) = delete;
		MUpdate& operator=(MUpdate&&) = delete;
	private:
		unsigned int milliseconds;
		static void MSGID_Update() {}
	public:
		MUpdate(unsigned int milliseconds)
			: MGeneric(MSGID_Update)
			, milliseconds(milliseconds)
		{

		}
		unsigned int GetMilliseconds() const
		{
			return milliseconds;
		}
		static bool Is(const MGeneric* message)
		{
			return message && message->GetId() == MSGID_Update;
		}
		static const MUpdate* From(const MGeneric* message)
		{
			return static_cast<const tggd::common::MUpdate*>(message);
		}

	};
}