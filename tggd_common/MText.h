#pragma once
#include "MGeneric.h"
#include <string>
namespace tggd::common
{
	class MText : public MGeneric
	{
		MText() = delete;
		MText(const MText&) = delete;
		MText(MText&&) = delete;
		MText& operator=(const MText&) = delete;
		MText& operator=(MText&&) = delete;
	private:
		std::string text;
		static void MSGID_TextInput() {}
	public:
		MText(const std::string& text)
			: MGeneric(MSGID_TextInput)
			, text(text)
		{

		}
		const std::string& GetText() const
		{
			return text;
		}
		static bool Is(const MGeneric* message)
		{
			return message && message->GetId() == MSGID_TextInput;
		}
		static const MText* From(const MGeneric* message)
		{
			return static_cast<const tggd::common::MText*>(message);
		}
	};
}
