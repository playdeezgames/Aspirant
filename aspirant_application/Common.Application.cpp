#include "Common.Application.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "Data.JSON.h"
namespace common::Application
{
#define PROPERTY_WIDTH "width"
#define PROPERTY_HEIGHT "height"
#define PROPERTY_LOGICAL_WIDTH "logicalWidth"
#define PROPERTY_LOGICAL_HEIGHT "logicalHeight"
#define PROPERTY_TITLE "title"
#define PROPERTY_ICON "icon"
#define PROPERTY_MIXER_FREQUENCY "mixerFrequency"
#define PROPERTY_CHANNEL_COUNT "channelCount"
#define PROPERTY_CHUNK_SIZE "chunkSize"

	static SDL_Window* window;
	static SDL_Renderer* renderer;

	extern void Start(SDL_Renderer*);
	extern bool IsRunning();
	extern void Update(Uint32);
	extern void Render(SDL_Renderer*);
	extern void HandleEvent(const SDL_Event&);
	extern void Finish();
	namespace ConfigurationConstants
	{
		extern std::string APPLICATION;
	}


	static void DoStart()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		Mix_Init(MIX_INIT_OGG);
		auto properties = data::JSON::Load(ConfigurationConstants::APPLICATION);
		int windowWidth = properties[PROPERTY_WIDTH];
		int windowHeight = properties[PROPERTY_HEIGHT];
		int logicalWidth = properties[PROPERTY_LOGICAL_WIDTH];
		int logicalHeight = properties[PROPERTY_LOGICAL_HEIGHT];
		std::string windowTitle = properties[PROPERTY_TITLE];
		std::string iconFileName = properties[PROPERTY_ICON];
		int mixerFrequency = properties[PROPERTY_MIXER_FREQUENCY];
		int channelCount = properties[PROPERTY_CHANNEL_COUNT];
		int chunkSize = properties[PROPERTY_CHUNK_SIZE];
		Mix_OpenAudio
		(
			mixerFrequency,
			MIX_DEFAULT_FORMAT,
			channelCount,
			chunkSize
		);

		SDL_CreateWindowAndRenderer(
			windowWidth,
			windowHeight,
			0,
			&window,
			&renderer);
		SDL_RenderSetLogicalSize(renderer, logicalWidth, logicalHeight);
		SDL_SetWindowTitle(window, windowTitle.c_str());
		auto iconSurface = IMG_Load(iconFileName.c_str());
		SDL_SetWindowIcon(window, iconSurface);
		SDL_FreeSurface(iconSurface);
		Start(renderer);
	}


	static void DoPump()
	{
		SDL_Event evt;
		auto currentTicks = SDL_GetTicks();
		while (IsRunning())
		{
			auto frameTicks = SDL_GetTicks();
			Update(frameTicks - currentTicks);
			currentTicks = frameTicks;
			Render(renderer);
			SDL_RenderPresent(renderer);
			if (SDL_PollEvent(&evt))
			{
				HandleEvent(evt);
			}
		}

	}

	static void DoFinish()
	{
		Finish();
		if (renderer)
		{
			SDL_DestroyRenderer(renderer);
			renderer = nullptr;
		}
		if (window)
		{
			SDL_DestroyWindow(window);
			window = nullptr;
		}
		Mix_CloseAudio();
		Mix_Quit();
		SDL_Quit();
	}

	int Run(const std::vector<std::string>& arguments)
	{
		DoStart();
		DoPump();
		DoFinish();
		return 0;
	}
}
