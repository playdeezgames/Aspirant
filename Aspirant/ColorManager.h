#pragma once
#include "CommonDescriptorManager.h"
#include <string>
#include <SDL.h>
#include "IDataStore.h"
namespace tggd::common
{
	class ColorManager : public CommonDescriptorManager<SDL_Color>, public IDataStore<SDL_Color>
	{
	protected:
		SDL_Color* ParseDescriptor(const nlohmann::json&);
	public:
		ColorManager(tggd::common::FinishManager&);
		const SDL_Color& Get(const std::string&) const;
	};
}