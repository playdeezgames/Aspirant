#pragma once
#include "MGeneric.h"
namespace tggd::common
{
	class MUpdate : public MGeneric
	{
	private:
		unsigned int milliseconds;
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
		static void MSGID_Update() {}
	};
}