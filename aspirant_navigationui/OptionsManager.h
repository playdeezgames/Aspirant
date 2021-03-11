#pragma once
#include <string>
#include "SoundManager.h"
namespace aspirant::navigationui
{
	class OptionsManager
	{
	private:
		std::string fileName;
		tggd::common::SoundManager& soundManager;
	public:
		OptionsManager(tggd::common::SoundManager&, const std::string&);
		void Start();
		void Save() const;
	};
}