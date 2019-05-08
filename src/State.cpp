#include "State.h"
#include "InputManager.h"
#include "CameraFollower.h"
#include "Alien.h"

 #define PI 3.1415

 State::State(){
  quitRequested = false;
 	objectArray = vector<shared_ptr<GameObject>>();
  srand(time(NULL));

 	LoadAssets();
	
  music.play(-1);

	this->map = new GameObject();
	TileSet* tiles = new TileSet(*map, 64, 64, "assets/img/tileset.png");

	Component* tileMap = new TileMap(*map, "assets/map/tileMap.txt", tiles);

	this->map->AddComponent(tileMap);
	this->map->box = Rect();

	GameObject* go = new GameObject();
	go->AddComponent(new Alien(*go, 8));
	go->box.SetPosition(Vec2(512-go->box.w/2, 300-go->box.h/2));
	
	objectArray.emplace_back(map);
	
	AddObject(go);
 }

 State::~State(){
   objectArray.clear();
 }

 bool State::QuitRequested(){
   return quitRequested;
 }

 void State::LoadAssets(){
		this->bg = new GameObject();
  	bgScreen = new Sprite(*this->bg,"assets/img/ocean.jpg");
  	this->bg->AddComponent(bgScreen);
		this->bg->AddComponent(new CameraFollower(*this->bg));
 		objectArray.emplace_back(bg);
 		music.open("assets/audio/stageState.ogg");
 }

 void State::Update(float dt) {

	Camera::Update(dt);
	this->map->Update(dt);
	
	quitRequested = InputManager::GetInstance().QuitRequested();

 	for(auto& i: objectArray){
 		i->Update(dt);
	}

 	for(int i = objectArray.size()-1; i >= 0; i--)
 		if(objectArray[i] != nullptr){
 			if(objectArray[i]->IsDead())
 				objectArray.erase(objectArray.begin()+i);
 		}
 }

 void State::Render(){
	
	bg->Render();

	for(auto& i: objectArray)
		i->Render();
 }

void State::Start(){

	for(auto& i : this->objectArray)
		i->Start();

	this->started = true;
}

 weak_ptr<GameObject> State::AddObject (GameObject *go){

	shared_ptr<GameObject> goShared = shared_ptr<GameObject>(go);
	this->objectArray.push_back(goShared);

	if(this->started)
		goShared->Start();

	return goShared;
 }
 
 weak_ptr<GameObject> State::GetObjectPtr(GameObject* go){
	weak_ptr<GameObject> object = weak_ptr<GameObject>();

	for(auto goShared : this->objectArray)
		if(goShared.get() == go)
			object = goShared;

	return object;
}
