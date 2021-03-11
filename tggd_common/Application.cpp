#include "Application.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "MEvent.h"
#include "MRender.h"
#include "MUpdate.h"
#include "Utility.h"
#include "JSONUtility.h"
namespace tggd::common
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

	Application* Application::s_application = nullptr;

	Application::Application
	(
		const std::string& fileName
	)
		: MessageHandler(nullptr)
		, window(nullptr)
		, renderer(nullptr)
		, windowWidth(0)
		, windowHeight(0)
		, logicalWidth(0)
		, logicalHeight(0)
		, windowTitle("")
		, iconFileName("")
		, mixerFrequency(0)
		, channelCount(0)
		, chunkSize(0)
	{
		if (!s_application)
		{
			s_application = this;
		}
		auto properties = tggd::data::JSONUtility::LoadJSON(fileName);
		windowWidth = (int)properties[PROPERTY_WIDTH];
		windowHeight = (int)properties[PROPERTY_HEIGHT];
		logicalWidth = (int)properties[PROPERTY_LOGICAL_WIDTH];
		logicalHeight = (int)properties[PROPERTY_LOGICAL_HEIGHT];
		windowTitle = properties[PROPERTY_TITLE];
		iconFileName = properties[PROPERTY_ICON];
		mixerFrequency = (int)properties[PROPERTY_MIXER_FREQUENCY];
		channelCount = (int)properties[PROPERTY_CHANNEL_COUNT];
		chunkSize = (int)properties[PROPERTY_CHUNK_SIZE];
	}

	void Application::DoStart()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		Mix_Init(MIX_INIT_OGG);
		Mix_OpenAudio
		(
			s_application->mixerFrequency, 
			MIX_DEFAULT_FORMAT, 
			s_application->channelCount, 
			s_application->chunkSize
		);

		SDL_CreateWindowAndRenderer(
			s_application->windowWidth,
			s_application->windowHeight,
			0,
			&s_application->window,
			&s_application->renderer);
		SDL_RenderSetLogicalSize(s_application->renderer, s_application->logicalWidth, s_application->logicalHeight);
		SDL_SetWindowTitle(s_application->window, s_application->windowTitle.c_str());
		auto iconSurface = IMG_Load(s_application->iconFileName.c_str());
		SDL_SetWindowIcon(s_application->window, iconSurface);
		SDL_FreeSurface(iconSurface);

		s_application->Start(s_application->renderer);
	}

	void Application::DoPump()
	{
		SDL_Event evt;
		auto currentTicks = SDL_GetTicks();
		while(s_application->IsRunning())
		{
			auto frameTicks = SDL_GetTicks();
			s_application->Broadcast(MUpdate(frameTicks - currentTicks));
			currentTicks = frameTicks;
			s_application->Broadcast(MRender(s_application->renderer));
			SDL_RenderPresent(s_application->renderer);
			if (SDL_PollEvent(&evt))
			{
				s_application->HandleBroadcast(MEvent(evt));
			}
		}

	}

	void Application::DoFinish()
	{
		s_application->Finish();
		if (s_application->renderer)
		{
			SDL_DestroyRenderer(s_application->renderer);
			s_application->renderer = nullptr;
		}
		if (s_application->window)
		{
			SDL_DestroyWindow(s_application->window);
			s_application->window = nullptr;
		}
		Mix_CloseAudio();
		Mix_Quit();
		SDL_Quit();
	}


	int Application::Run(const std::vector<std::string>& arguments)
	{
		if (s_application)
		{
			DoStart();
			DoPump();
			DoFinish();
		}
		return 0;
	}
}