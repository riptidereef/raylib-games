#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

        int tileSize;

        vector<Color> tileColors;

        void ReadMap(string path);
        void PrintMap();
        void DrawMap();

    public:
        void Init();
        void Update();
        void Shutdown();
};