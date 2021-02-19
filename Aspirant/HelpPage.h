#pragma once
#include "json.hpp"
#include "StaticText.h"
#include <string>
#include <vector>
namespace tggd::common
{
	class HelpPage
	{
	private:
		std::string nextPage;
		std::string previousPage;
		std::vector<tggd::common::Label> labels;
	public:
		HelpPage(const nlohmann::json&, const tggd::common::FontManager&);
		const std::string& GetNextPage() const;
		const std::string& GetPreviousPage() const;
		const std::vector< tggd::common::Label>& GetLabels() const;
	};
}
