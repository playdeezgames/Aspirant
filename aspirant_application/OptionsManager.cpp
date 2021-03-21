#include "OptionsManager.h"
#include "JSONUtility.h"
#include "SoundManager.h"
namespace aspirant::navigationui::OptionsManager
{
	const std::string PROPERTY_MUTED = "muted";
	const std::string PROPERTY_SFX_VOLUME = "sfxVolume";
	const std::string PROPERTY_MUX_VOLUME = "muxVolume";
	static std::string fileName;

	void Start(const std::string& filename)
	{
		fileName = filename;
		auto properties = tggd::data::JSONUtility::LoadJSON(fileName);
		tggd::common::SoundManager::SetMuted((bool)properties[PROPERTY_MUTED]);
		tggd::common::SoundManager::SetSfxVolume((int)properties[PROPERTY_SFX_VOLUME]);
		tggd::common::SoundManager::SetMuxVolume((int)properties[PROPERTY_MUX_VOLUME]);
	}

	void Save()
	{
		nlohmann::json properties;
		properties[PROPERTY_MUTED] = tggd::common::SoundManager::IsMuted();
		properties[PROPERTY_MUX_VOLUME] = tggd::common::SoundManager::GetMuxVolume();
		properties[PROPERTY_SFX_VOLUME] = tggd::common::SoundManager::GetSfxVolume();
		tggd::data::JSONUtility::SaveJSON(fileName, properties);
	}
}