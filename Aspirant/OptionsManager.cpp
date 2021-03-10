#include "OptionsManager.h"
#include "Utility.h"
#include <io.h>
#include "JSONUtility.h"
namespace aspirant
{
	OptionsManager::OptionsManager
	(
		tggd::common::SoundManager& soundManager,
		const std::string& fileName
	)
		: fileName(fileName)
		, soundManager(soundManager)
	{
	}

	const std::string PROPERTY_MUTED = "muted";
	const std::string PROPERTY_SFX_VOLUME = "sfxVolume";
	const std::string PROPERTY_MUX_VOLUME = "muxVolume";

	void OptionsManager::Start()
	{
		auto properties = tggd::common::JSONUtility::LoadJSON(fileName);
		soundManager.SetMuted((bool)properties[PROPERTY_MUTED]);
		soundManager.SetSfxVolume((int)properties[PROPERTY_SFX_VOLUME]);
		soundManager.SetMuxVolume((int)properties[PROPERTY_MUX_VOLUME]);
	}

	void OptionsManager::Save() const
	{
		nlohmann::json properties;
		properties[PROPERTY_MUTED] = soundManager.IsMuted();
		properties[PROPERTY_MUX_VOLUME] = soundManager.GetMuxVolume();
		properties[PROPERTY_SFX_VOLUME] = soundManager.GetSfxVolume();
		tggd::common::JSONUtility::SaveJSON(fileName, properties);
	}
}