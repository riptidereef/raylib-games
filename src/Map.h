#pragma once
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>
#include <raylib.h>
#include <string>
#include <iostream>
#include "raymath.h"
#include "TextureManager.h"
using namespace std;

class Map {
    private:
        string basePath = "../data/tilemap/";
        tmx::Map tilemap;
        Texture tilemapTexture;
        int numTileRows, numTileCols;
        int tileHeight = 32;
        int tileWidth = 32;

    public:
        void Init(string name);
        void Draw();
};