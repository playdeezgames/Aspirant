#include "Application.h"
#include "RNGUtility.h"
#include "Utility.h"
int main(int argc, char** argv)
{
	tggd::common::RNGUtility::SeedRandomNumberGenerator();
	auto arguments = tggd::common::Utility::CommandLineToStringVector(argc, argv);
	return tggd::common::Application::Run(arguments);
}