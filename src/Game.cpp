#include "Game.h"

void Game::Init() {
    screenWidth = 160 * 10;
    screenHeight = 90 * 10;
    virtualScreenWidth = 160 * 6;
    virtualScreenHeight = 90 * 6;
    virtualRatio = (float)screenWidth/(float)virtualScreenWidth;

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "RPG");
    SetTargetFPS(240);

    target = LoadRenderTexture(virtualScreenWidth, virtualScreenHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    sourceRect = {0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height};

    destRect = {((float)screenWidth - (float)target.texture.width * virtualRatio) / 2.0f, 
                ((float)screenHeight - (float)target.texture.height * virtualRatio) / 2.0f,
                (float)target.texture.width * virtualRatio,
                (float)target.texture.height * virtualRatio};

    backgroundColor = {62, 52, 50, 255};

    icon = LoadImage("../data/textures/Icon.png");
    SetWindowIcon(icon);

    player.Init();

    tilemap.Init("StoneDungeon.tmx");
}

void Game::Update(float dt) {

    BeginTextureMode(target);
        ClearBackground(BLACK);
        tilemap.DrawMap();
        player.Update(dt);
    EndTextureMode();

    BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(target.texture, sourceRect, destRect, {0, 0}, 0.0f, WHITE);
    EndDrawing();
}

void Game::Shutdown() {
    TextureManager::UnloadAll();
    UnloadRenderTexture(target);
}