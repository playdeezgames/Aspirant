#include "Options.h"
#include "Data.JSON.h"
#include "Common.Sounds.h"
namespace Options
{
	const std::string PROPERTY_MUTED = "muted";
	const std::string PROPERTY_SFX_VOLUME = "sfxVolume";
	const std::string PROPERTY_MUX_VOLUME = "muxVolume";
	static std::string fileName;

	void Start(const std::string& filename)
	{
		fileName = filename;
		auto properties = data::JSON::Load(fileName);
		common::Sounds::SetMuted((bool)properties[PROPERTY_MUTED]);
		common::Sounds::SetSfxVolume((int)properties[PROPERTY_SFX_VOLUME]);
		common::Sounds::SetMuxVolume((int)properties[PROPERTY_MUX_VOLUME]);
	}

	void Save()
	{
		nlohmann::json properties;
		properties[PROPERTY_MUTED] = common::Sounds::IsMuted();
		properties[PROPERTY_MUX_VOLUME] = common::Sounds::GetMuxVolume();
		properties[PROPERTY_SFX_VOLUME] = common::Sounds::GetSfxVolume();
		data::JSON::Save(fileName, properties);
	}
}