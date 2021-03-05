#pragma once
#include "MGeneric.h"
#include <string>
namespace tggd::common
{
	class MText : public MGeneric
	{
	private:
		std::string text;
	public:
		MText(const std::string& text)
			: MGeneric(MSGID_TextInput)
			, text(text)
		{

		}
		static void MSGID_TextInput() {}
		const std::string& GetText() const
		{
			return text;
		}
	};
}
