#include "Game.h"

void Game::Init() {
    screenWidth = 160 * 10;
    screenHeight = 90 * 10;

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "RPG");
    SetTargetFPS(240);

    backgroundColor = {63, 112, 77, 255};

    icon = LoadImage("../data/textures/Icon.png");
    SetWindowIcon(icon);

    camera.target = {0.0f, 0.0f};
    camera.offset = {(float)screenWidth / 2, (float)screenHeight / 2};
    camera.rotation = 0.0f;
    zoomLevel = 4.0f;
    camera.zoom = zoomLevel;

    mainWorld.Init("IsometricMap.tmx");
}

void Game::Update(float dt) {

    int mouseX = GetMouseX();
    int mouseY = GetMouseY();

    Vector2 worldPos = GetScreenToWorld2D((Vector2){(float)mouseX, (float)mouseY}, camera);
    int tileX = round((float)worldPos.x / 32.0f + (float)worldPos.y / 16.0f);
    int tileY = round(-(float)worldPos.x / 32.0f + (float)worldPos.y / 16.0f);

    cout << "Tile Coordinates: " << tileX << ", " << tileY << endl;

    BeginDrawing();
        ClearBackground(backgroundColor);

        BeginMode2D(camera);
            mainWorld.Draw();

           
        EndMode2D();

        DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, WHITE);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
    EndDrawing();
}


void Game::Shutdown() {
    TextureManager::UnloadAll();
}