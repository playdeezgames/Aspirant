#pragma once
#include "CommonDescriptorManager.h"
#include <string>
#include <SDL.h>
#include "IDataStore.h"
namespace tggd::graphics
{
	class ColorManager 
		: public tggd::common::CommonDescriptorManager<SDL_Color>
		, public tggd::data::IDataStore<SDL_Color>
	{
		ColorManager() = delete;
		ColorManager(const ColorManager&) = delete;
		ColorManager(ColorManager&&) = delete;
		ColorManager& operator=(const ColorManager&) = delete;
		ColorManager& operator=(ColorManager&&) = delete;
	protected:
		SDL_Color* ParseDescriptor(const std::string&, const nlohmann::json&);
	public:
		ColorManager(tggd::common::FinishManager&);
		const SDL_Color& operator[](const std::string&) const;
	};
}