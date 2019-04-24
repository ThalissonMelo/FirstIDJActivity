#include "Camera.h"
#include "Game.h"

GameObject* Camera::focus = nullptr;
Vec2 Camera::pos = Vec2();
Vec2 Camera::speed = Vec2(300, 300);

void Camera::Follow(GameObject* newFocus){
  focus = newFocus;
}
void Camera::Unfollow(){
  focus = nullptr;
}

void Camera::Update(float dt) {
  if(focus == nullptr)
  {
		if(InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY))
			pos.y -= speed.y*dt;
		
    if(InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY))
			pos.y += speed.y*dt;
		
    if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY))
			pos.x -= speed.x*dt;
		
    if(InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY))
			pos.x += speed.x*dt;
	}
  else
  {
		if(InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY))
			focus->box.y -= speed.y*dt;
		
    if(InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY))
			focus->box.y += speed.y*dt;
		
    if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY))
			focus->box.x -= speed.x*dt;
		
    if(InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY))
			focus->box.x += speed.x*dt;
		
    int w, h;
		
    SDL_GetRendererOutputSize(Game::getInstance().getRenderer(), &w, &h);
		pos.x = focus->box.GetCenter().x-w/2;
		pos.y = focus->box.GetCenter().y-h/2;
	}
}