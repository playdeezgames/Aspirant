#pragma once
#include <string>
#include "Game.Descriptor.Common.h"
#include "json.hpp"
#include <SDL.h>
#include "Common.XY.h"
#include <optional>
namespace game::object
{
	class Common
	{
	private:
		nlohmann::json& model;
	public:
		Common(nlohmann::json&);
		game::descriptor::Common GetDescriptor() const;
		std::string GetType() const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void Draw(SDL_Renderer*, common::XY<int>) const;
	};
}