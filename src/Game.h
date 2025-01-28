#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>
#include "rlgl.h"
#include "raymath.h"
using namespace std;

class Game {
    private:
        int screenWidth;
        int screenHeight;
        int framesPerSecond;

        tmx::Map tilemap;
        Texture tilemapTexture;

        int tileWidth = 16;
        int tileHeight = 16;
        int numTileRows;
        int numTileCols;

        int testInt;

        void Debug();

    public:
        void Init();
        void Update(float dt);
        void Shutdown();
};