#include "Game.h"

void Game::Init() {
    screenWidth = 640;
    screenHeight = 360;

    InitWindow(screenWidth, screenHeight, "Window");

    ReadMap("./data/maps/01.txt");
}

void Game::Update() {
    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
}

void Game::Shutdown() {

}

void Game::ReadMap(string path) {
    mapFile.open(path);

    if (!mapFile.is_open()) {
        cout << "Error in opening file from path: " << path << endl;
        return;
    }
    else {
        string line;
        while (getline(mapFile, line)) {
            cout << line << endl;
        }
    }
}

