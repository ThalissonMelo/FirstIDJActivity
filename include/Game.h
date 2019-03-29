#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "../include/SDL_include.h"
#include <bits/stdc++.h>
#include "State.h"
#include <SDL2/SDL_mixer.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace std;

class Game{
	public:
		~Game();
		void run();
		SDL_Renderer* getRenderer();
    State& getState();
    static Game& getInstance();
	private:
		Game(string title = "", int width = 10, int heigth = 10);
		SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
		static Game* instance;
};
