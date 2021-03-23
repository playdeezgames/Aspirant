#include "Common.Application.h"
#include "RNGUtility.h"
#include "Common.Utility.h"
#include <SDL.h>
int main(int argc, char** argv)
{
	tggd::common::RNGUtility::Seed();
	auto arguments = common::Utility::CommandLineToStringVector(argc, argv);
	return common::Application::Run(arguments);
}

