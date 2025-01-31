#pragma once
#include <iostream>
#include <string>
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>
#include <raylib.h>
#include "TextureManager.h"
using namespace std;

class Tilemap {
    private:
        string basePath = "../data/tilemap/";
        tmx::Map tilemap;
        Texture2D tilemapTexture;
        int tileWidth = 16;
        int tileHeight = 16;
        int numTileCols;
        int numTileRows;
        float scale = 3.0f;

    public:
        void Init(const string& tilemapName);
        void DrawMap();
};