#include "Application.h"
#include "RNGUtility.h"
#include "Utility.h"
#include <SDL.h>
int main(int argc, char** argv)
{
	tggd::common::RNGUtility::Seed();
	auto arguments = tggd::common::Utility::CommandLineToStringVector(argc, argv);
	return tggd::common::Application::Run(arguments);
}

