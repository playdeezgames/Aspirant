#pragma once
#include "BaseDescriptorManager.h"
#include <string>
#include <SDL.h>
#include "IDataStore.h"
namespace tggd::common
{
	class ColorManager : public BaseDescriptorManager<std::string, SDL_Color>, public IDataStore<SDL_Color>
	{
	protected:
		std::string ParseKey(const std::string&);
		SDL_Color* ParseDescriptor(const nlohmann::json&);
	public:
		ColorManager(tggd::common::FinishManager&);
		const SDL_Color& Get(const std::string&) const;
	};
}