#pragma once
#include "Application.h"
namespace aspirant
{
	class AspirantApplication : public tggd::common::Application
	{
	protected:
		bool IsRunning() const;
		void Start();
		void Finish();
	public:
		AspirantApplication();
	};
}
