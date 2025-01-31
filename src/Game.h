#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rlgl.h"
#include "raymath.h"
#include "Player.h"
#include "Tilemap.h"
#include "TextureManager.h"
using namespace std;

class Game {
    private:
        int screenWidth;
        int screenHeight;

        Texture tilemapTexture;

        int tileWidth = 16;
        int tileHeight = 16;
        int numTileRows;
        int numTileCols;
        float scale = 3.0f;

        Image icon;

        Player player;

        Tilemap tilemap;

    public:
        void Init();
        void Update(float dt);
        void Shutdown();
};