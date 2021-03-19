#pragma once
#include <string>
namespace aspirant
{
	class ConfigurationConstants
	{
	public:
		const std::string APPLICATION = "config/ui/application.json";
		const std::string TEXTURE = "config/graphics/textures.json";
		const std::string SPRITE = "config/graphics/sprites.json";
		const std::string COLOR = "config/graphics/colors.json";
		const std::string FONTS = "config/graphics/fonts.json";
		const std::string LAYOUTS = "config/ui/layouts.json";
		const std::string STRINGS = "config/data/strings.json";
		const std::string INTS = "config/data/ints.json";
		const std::string FLAGS = "config/data/flags.json";
		const std::string OPTIONS = "config/options.json";
		const std::string SFX = "config/audio/sfx.json";
		const std::string MUX = "config/audio/mux.json";
		const std::string DESCRIPTORS = "config/game/descriptors.json";
		const std::string SCENARIOS = "scenarios/scenarios.json";
	};
}