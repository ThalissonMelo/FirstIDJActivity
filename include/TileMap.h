#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <bits/stdc++.h>
#include "TileSet.h"
#include "GameObject.h"

using namespace std;

class TileMap : public Component{
  public:
    TileMap (GameObject& associated, string file, TileSet* tileSet);
    ~TileMap();
    void Load (string file);
    void SetTileSet (TileSet* tileSet);
    int At (int x, int y, int z);
    void Render ();
    void RenderLayer (int layer, int cameraX=0, int cameraY=0);
    int GetWidth ();
    int GetHeight ();
    int GetDepth ();
    void Update(float dt);
    bool Is(string type); 
  private:
    vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;
};

#endif