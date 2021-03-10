#include "JSONUtility.h"
#include <fstream>
namespace tggd::data
{
	nlohmann::json JSONUtility::LoadJSON(const std::string& fileName)
	{
		nlohmann::json document;
		std::ifstream input(fileName);
		if (input.is_open())
		{
			input >> document;
			input.close();
		}
		return document;
	}

	void JSONUtility::SaveJSON(const std::string& fileName, const nlohmann::json& document)
	{
		std::ofstream output(fileName);
		if (output.is_open())
		{
			output << document;
			output.close();
		}
	}
}

