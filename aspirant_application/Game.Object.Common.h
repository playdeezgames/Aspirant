#pragma once
#include <string>
#include "Game.Descriptor.Common.h"
#include "json.hpp"
#include <SDL.h>
#include "Common.XY.h"
namespace game::object
{
	class Common
	{
	private:
		std::string descriptorName;
	public:
		Common(const std::string& descriptorName) : descriptorName(descriptorName) {}
		const ::game::descriptor::Common& GetDescriptor() const;
		const std::string& GetType() const;
		bool CanCover(const Common*) const;
		bool IsTerrain() const;
		bool IsCreature() const;
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
		void Draw(SDL_Renderer*, common::XY<int>) const;
	};
}