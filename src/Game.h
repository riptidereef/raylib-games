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
        int virtualScreenWidth;
        int virtualScreenHeight;
        float virtualRatio = (float)screenWidth/(float)virtualScreenWidth;

        RenderTexture2D target;

        Rectangle sourceRect;
        Rectangle destRect;

        Color backgroundColor;

        Image icon;
        Tilemap tilemap;

        Player player;

    public:
        void Init();
        void Update(float dt);
        void Shutdown();
};