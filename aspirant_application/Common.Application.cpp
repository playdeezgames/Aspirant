#include "Common.Application.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "Data.JSON.h"
namespace common::Application
{
	const std::string PROPERTY_WIDTH = "width";
	const std::string PROPERTY_HEIGHT = "height";
	const std::string PROPERTY_LOGICAL_WIDTH = "logicalWidth";
	const std::string PROPERTY_LOGICAL_HEIGHT = "logicalHeight";
	const std::string PROPERTY_TITLE = "title";
	const std::string PROPERTY_ICON = "icon";
	const std::string PROPERTY_MIXER_FREQUENCY = "mixerFrequency";
	const std::string PROPERTY_CHANNEL_COUNT = "channelCount";
	const std::string PROPERTY_CHUNK_SIZE = "chunkSize";

	static SDL_Window* window = nullptr;
	static SDL_Renderer* renderer = nullptr;

	extern void Start(SDL_Renderer*, const std::vector<std::string>&);
	extern bool IsRunning();
	extern void Update(Uint32);
	extern void Render(SDL_Renderer*);
	extern void HandleEvent(const SDL_Event&);
	extern void Finish();

	static void DoStart(const std::string& configFile, const std::vector<std::string>& arguments)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		Mix_Init(MIX_INIT_OGG);
		auto properties = data::JSON::Load(configFile);
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
		Start(renderer, arguments);
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

	static void DestroyRenderer()
	{
		if (renderer)
		{
			SDL_DestroyRenderer(renderer);
			renderer = nullptr;
		}
	}

	static void DestroyWindow()
	{
		if (window)
		{
			SDL_DestroyWindow(window);
			window = nullptr;
		}
	}

	static void DoFinish()
	{
		Finish();
		DestroyRenderer();
		DestroyWindow();
		Mix_CloseAudio();
		Mix_Quit();
		SDL_Quit();
	}

	int Run(const std::string& configFile, const std::vector<std::string>& arguments)
	{
		DoStart(configFile, arguments);
		DoPump();
		DoFinish();
		return 0;
	}
}
