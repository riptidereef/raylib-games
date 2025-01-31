#include "Game.h"

void Game::Init() {
    screenWidth = 1920;
    screenHeight = 1080;

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "RPG");
    SetTargetFPS(240);

    tilemapTexture = TextureManager::GetTexture("DungeonTileset.png");

    icon = LoadImage("../data/textures/Icon.png");
    SetWindowIcon(icon);

    player.Init();

    tilemap.Init("StoneDungeon.tmx");
}

void Game::Update(float dt) {
    BeginDrawing();
        Color backgroundColor = {62, 52, 50, 255};
        ClearBackground(backgroundColor);

        tilemap.DrawMap();

        player.Update(dt);

        DrawFPS(0, 0);
    EndDrawing();
}

void Game::Shutdown() {
    TextureManager::UnloadAll();
}