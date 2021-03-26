#pragma once
#include <string>
#include "json.hpp"
#include <SDL.h>
#include "Common.XY.h"
namespace game::object
{
	class Common;
}
namespace game::descriptor
{
	class Common
	{
		Common() = delete;
		Common(const Common&) = delete;
		Common(Common&&) = delete;
		Common& operator=(const Common&) = delete;
		Common& operator=(Common&&) = delete;
	private:
		const std::string PROPERTY_TYPE = "type";
		const std::string PROPERTY_SPRITE = "sprite";
		std::string descriptorType;
		std::string name;
		std::string sprite;
	public:
		Common(const std::string& name, const nlohmann::json& properties)
			: descriptorType(properties[PROPERTY_TYPE])
			, name(name)
			, sprite(properties[PROPERTY_SPRITE])
		{
		}
		const std::string& GetType() const
		{
			return descriptorType;
		}
		const std::string& GetName() const
		{
			return name;
		}
		game::object::Common* CreateObject() const;
		const std::string& GetSprite() const
		{
			return sprite;
		}
		void Draw(SDL_Renderer*, common::XY<int>) const;
	};
}
