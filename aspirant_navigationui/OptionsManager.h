#pragma once
#include <string>
#include "SoundManager.h"
namespace aspirant::navigationui
{
	class OptionsManager
	{
		OptionsManager() = delete;
		OptionsManager(const OptionsManager&) = delete;
		OptionsManager(OptionsManager&&) = delete;
		OptionsManager& operator=(const OptionsManager&) = delete;
		OptionsManager& operator=(OptionsManager&&) = delete;
	private:
		std::string fileName;
		tggd::common::SoundManager& soundManager;
	public:
		OptionsManager(tggd::common::SoundManager&, const std::string&);
		void Start();
		void Save() const;
	};
}