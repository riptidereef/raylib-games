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

    tilemapTexture = LoadTexture("../data/tilemap/DungeonTileset.png");

    if (tilemapTexture.id != 0) {
        numTileRows = tilemapTexture.height / tileHeight;
        numTileCols = tilemapTexture.width / tileWidth;
    }

    testInt = 0;
}

void Game::Update(float dt) {
    BeginDrawing();
        ClearBackground(RAYWHITE);

        Debug();
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            testInt++;
        }

    EndDrawing();
}

void Game::Shutdown() {
    UnloadTexture(tilemapTexture);
}

void Game::Debug() {

    for (const auto& layer : tilemap.getLayers()) {

        if (layer->getType() == tmx::Layer::Type::Tile && layer->getName() == "Ground") {

            const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
            const auto& tiles = tileLayer.getTiles();

            const auto& currTile = tiles[testInt];


            int tilemapRow = (currTile.ID - 1) / numTileCols;
            int tilemapCol = (currTile.ID - 1) % numTileCols;

            Rectangle sourceRect = {
                tilemapCol * tileWidth,
                tilemapRow * tileWidth,
                tileWidth,
                tileHeight
            };

            Rectangle destRect = {0, 0, tileWidth * 10, tileHeight * 10};

            Vector2 origin = {0, 0};

            DrawTexturePro(tilemapTexture, sourceRect, destRect, origin, 0, WHITE);

            break;
        }
    }
}