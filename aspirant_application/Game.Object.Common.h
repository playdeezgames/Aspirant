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
		const ::game::descriptor::Common& descriptor;
	public:
		Common(const ::game::descriptor::Common& descriptor) : descriptor(descriptor) {}
		const ::game::descriptor::Common& GetDescriptor() const
		{
			return descriptor;
		}
		virtual bool CanCover(const Common*) const = 0;
		virtual bool IsTerrain() const = 0;
		virtual bool IsCreature() const = 0;
		virtual void FromJSON(const nlohmann::json&) = 0;
		virtual void Draw(SDL_Renderer*, common::XY<int>) const;
		virtual nlohmann::json ToJSON() const = 0;
	};
}