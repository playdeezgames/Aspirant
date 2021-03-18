#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include "MessageHandler.h"
namespace tggd::common
{
	class Application : public MessageHandler
	{
	private:
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		SDL_Window* window;
		std::string windowTitle;
		std::string iconFileName;
		int windowWidth;
		int windowHeight;
		int logicalWidth;
		int logicalHeight;
		int mixerFrequency;
		int channelCount;
		int chunkSize;

		SDL_Renderer* renderer;

		static Application* s_application;
		static void DoStart();
		static void DoPump();
		static void DoFinish();
	protected:
		void Bootstrap(const std::string&);
		SDL_Renderer* GetRenderer() const { return renderer; }
		virtual bool IsRunning() const = 0;
		virtual void Start(SDL_Renderer*) = 0;
		virtual void Finish() = 0;
	public:
		Application();
		static int Run(const std::vector<std::string>&);
	};
}


