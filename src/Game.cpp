#include "Game.h"

void Game::Init() {
    screenWidth = 1920;
    screenHeight = 1080;
    framesPerSecond = 60;

    if (!tilemap.load("../data/tilemap/StoneDungeon.tmx")) {
        cout << "Failed to load tilemap." << endl;
    }

    InitWindow(screenWidth, screenHeight, "RPG");
    SetTargetFPS(framesPerSecond);
}

void Game::Update(float dt) {
    BeginDrawing();
        ClearBackground(SKYBLUE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Debug();
        }

    EndDrawing();
}

void Game::Shutdown() {

}

void Game::Debug() {
    for (const auto& layer : tilemap.getLayers()) {
        cout << "- " << layer->getName() << endl;
    }
}