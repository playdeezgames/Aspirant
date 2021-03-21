#include "JSONUtility.h"
#include <fstream>
namespace tggd::data::JSONUtility
{
	nlohmann::json LoadJSON(const std::string& fileName)
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

	void SaveJSON(const std::string& fileName, const nlohmann::json& document)
	{
		std::ofstream output(fileName);
		if (output.is_open())
		{
			output << document;
			output.close();
		}
	}
}
