#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "raymath.h"
#include "TextureManager.h"
#include "Map.h"
using namespace std;

class Game {
    private:
        int screenWidth;
        int screenHeight;
        Color backgroundColor;
        Image icon;

        Camera2D camera;
        float zoomLevel;

        Map mainWorld;

    public:
        void Init();
        void Update(float dt);
        void Shutdown();
};