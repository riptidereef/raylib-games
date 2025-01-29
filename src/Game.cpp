#include "Game.h"

void Game::Init() {
    screenWidth = 1920;
    screenHeight = 1080;

    if (!tilemap.load("../data/tilemap/StoneDungeon.tmx")) {
        cout << "Failed to load tilemap." << endl;
    }

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "RPG");
    SetTargetFPS(240);

    tilemapTexture = LoadTexture("../data/tilemap/DungeonTileset.png");

    if (tilemapTexture.id != 0) {
        numTileRows = tilemapTexture.height / tileHeight;
        numTileCols = tilemapTexture.width / tileWidth;
    }

    icon = LoadImage("../data/sprites/Icon.png");
    SetWindowIcon(icon);

    player.Init();
}

void Game::Update(float dt) {
    BeginDrawing();
        Color backgroundColor = {62, 52, 50, 255};
        ClearBackground(backgroundColor);

        Debug();

        player.Update(dt);

        DrawFPS(0, 0);

    EndDrawing();
}

void Game::Shutdown() {
    UnloadTexture(tilemapTexture);
}

void Game::Debug() {
    DrawMap(tilemap);
}

void Game::DrawMap(const tmx::Map& tilemap) {
    
    for (const auto& layer : tilemap.getLayers()) {

        if (layer->getType() == tmx::Layer::Type::Tile) {

            const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
            const auto& tiles = tileLayer.getTiles();

            int currTileNum = 0;
            int tileLayerCols = tileLayer.getSize().x;
            int tileLayerRows = tileLayer.getSize().y;

            for (const auto& currTile : tiles) {

                if (currTile.ID == 0) {
                    currTileNum++;
                    continue;
                }

                int tilemapRow = (currTile.ID - 1) / numTileCols;
                int tilemapCol = (currTile.ID - 1) % numTileCols;

                Rectangle sourceRect = {
                    (float)tilemapCol * tileWidth,
                    (float)tilemapRow * tileWidth,
                    (float)tileWidth,
                    (float)tileHeight
                };

                float destX = (currTileNum % tileLayerCols) * tileWidth * scale;
                float destY = (currTileNum / tileLayerCols) * tileHeight * scale;
                Rectangle destRect = {destX, destY, (float)tileWidth * scale, (float)tileHeight * scale};

                Vector2 origin = {0.0f, 0.0f};

                DrawTexturePro(tilemapTexture, sourceRect, destRect, origin, 0.0f, WHITE);

                currTileNum++;
            }
        }
    }
}