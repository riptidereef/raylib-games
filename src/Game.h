#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Game {
    private:
        int screenWidth;
        int screenHeight;

        ifstream mapFile;
        int numRows;
        int numCols;


        void ReadMap(string path);

    public:
        void Init();
        void Update();
        void Shutdown();
};