#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rlgl.h"
#include "raymath.h"
using namespace std;

class Game {
    private:
        int screenWidth;
        int screenHeight;
        int targetFPS = 60;

        ifstream mapFile;
        int numRows;
        int numCols;

        vector<vector<int>> mapGrid;
        pair<int, int> start;
        pair<int, int> finish;
        Vector2 cameraTarget;


        int tileSize;

        vector<Color> tileColors;

        Camera2D camera;

        vector<pair<int, int>> examplePath;
        float pathThickness = 2.5f;

        void ReadMap(string path);
        void PrintMap();
        void DrawMap();
        void DrawPath(vector<pair<int, int>>& path);
        void DrawGrid2D(int rows, int cols, int size, Color color);


    public:
        void Init();
        void Update();
        void Shutdown();
};