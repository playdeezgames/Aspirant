#pragma once
#include "MGeneric.h"
#include "Command.h"
namespace aspirant::commonui
{
	class MCommand: public tggd::common::MGeneric
	{
	private:
		Command command;
	public:
		MCommand(const Command& command)
			: MGeneric(MSGID_Command)
			, command(command)
		{

		}
		static void MSGID_Command() {}
		const Command& GetCommand() const
		{
			return command;
		}
	};
}
