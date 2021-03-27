#pragma once
#include <string>
#include "json.hpp"
#include <SDL.h>
#include "Common.XY.h"
#include "Game.Properties.h"
#include "Common.Properties.h"
#include "Graphics.Properties.h"
#include <optional>
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
			return model[common::Properties::TYPE];
		}
		const std::string& GetName() const
		{
			return name;
		}
		game::object::Common CreateObject(nlohmann::json&) const;
		std::string GetSprite() const
		{
			return model[graphics::Properties::SPRITE];
		}
		void Draw(SDL_Renderer*, common::XY<int>) const;
		bool CanCover(std::optional<game::object::Common>) const;
	};
}
