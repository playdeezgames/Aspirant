#include "Application.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "MEvent.h"
#include "MRender.h"
#include "Utility.h"
namespace tggd::common
{
	const std::string PROPERTY_WIDTH = "width";
	const std::string PROPERTY_HEIGHT = "height";
	const std::string PROPERTY_TITLE = "title";
	const std::string PROPERTY_ICON = "icon";
	const std::string PROPERTY_MIXER_FREQUENCY = "mixerFrequency";
	const std::string PROPERTY_CHANNEL_COUNT = "channelCount";
	const std::string PROPERTY_CHUNK_SIZE = "chunkSize";

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
		auto properties = Utility::LoadJSON(fileName);
		windowWidth = (int)properties[PROPERTY_WIDTH];
		windowHeight = (int)properties[PROPERTY_HEIGHT];
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
		SDL_SetWindowTitle(s_application->window, s_application->windowTitle.c_str());
		auto iconSurface = IMG_Load(s_application->iconFileName.c_str());
		SDL_SetWindowIcon(s_application->window, iconSurface);
		SDL_FreeSurface(iconSurface);

		s_application->Start();
	}

	void Application::DoPump()
	{
		SDL_Event evt;
		while(s_application->IsRunning())
		{
			s_application->Broadcast(MRender::MSGID_Draw);
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
