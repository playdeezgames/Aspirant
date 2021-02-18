#include "AspirantApplication.h"
namespace aspirant
{
	const std::string CONFIG_FILE = "config/application.json";

	AspirantApplication::AspirantApplication()
		: tggd::common::Application(CONFIG_FILE)
	{

	}

	bool AspirantApplication::IsRunning() const
	{
		return true;
	}

	void AspirantApplication::Start()
	{

	}

	void AspirantApplication::Finish()
	{

	}

	bool AspirantApplication::OnMessage(const tggd::common::MGeneric*)
	{
		return false;
	}


	AspirantApplication application;
}