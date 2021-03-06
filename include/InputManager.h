#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define SPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT
#define W_KEY SDLK_w
#define A_KEY SDLK_a
#define S_KEY SDLK_s
#define D_KEY SDLK_d

#include <SDL2/SDL.h>
#include<unordered_map>
#include <iostream>
#include "Vec2.h"

using namespace std;

class InputManager{
  public:
    bool KeyPress(int key);
    bool KeyRelease(int key);
    void Update();
    bool IsKeyDown(int key);
    bool MousePress(int button);
    bool MouseRelease(int button);
    bool IsMouseDown(int button);
    int GetMouseX();
    int GetMouseY();
    bool QuitRequested();
    static InputManager& GetInstance();
    Vec2 GetMousePosition();
  
  private:
    InputManager();
    ~InputManager();
    bool mouseState[6];
    int mouseUpdate[6];
    unordered_map<int, bool> keyState;
    unordered_map<int, int> keyUpdate;
    bool quitRequested;
    int updateCounter;
    int mouseX;
    int mouseY;
};

#endif