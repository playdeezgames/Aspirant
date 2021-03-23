#include "Common.Application.h"
#include "Common.RNG.h"
#include "Common.Utility.h"
#include <SDL.h>
int main(int argc, char** argv)
{
	common::RNG::Seed();
	auto arguments = common::Utility::CommandLineToStringVector(argc, argv);
	return common::Application::Run(arguments);
}

