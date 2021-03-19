#pragma once
#include "MGeneric.h"
#include "Command.h"
namespace aspirant::commonui
{
	class MCommand: public tggd::common::MGeneric
	{
	private:
		Command command;
		static void MSGID_Command() {}
	public:
		MCommand(const Command& command)
			: MGeneric(MSGID_Command)
			, command(command)
		{

		}
		const Command& GetCommand() const
		{
			return command;
		}
		static bool Is(const tggd::common::MGeneric* message)
		{
			return message->GetId() == MSGID_Command;
		}
		static const MCommand* From(const tggd::common::MGeneric* message)
		{
			return static_cast<const MCommand*>(message);
		}
	};
}
