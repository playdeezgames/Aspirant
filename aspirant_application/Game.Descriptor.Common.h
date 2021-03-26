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
		const nlohmann::json& model;
		std::string name;
	public:
		Common(const std::string& name, const nlohmann::json& model)
			: model(model)
			, name(name)
		{
		}
		std::string GetType() const
		{
			return model[PROPERTY_TYPE];
		}
		const std::string& GetName() const
		{
			return name;
		}
		game::object::Common* CreateObject() const;
		std::string GetSprite() const
		{
			return model[PROPERTY_SPRITE];
		}
		void Draw(SDL_Renderer*, common::XY<int>) const;
	};
}
