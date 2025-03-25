#include "Map.h"

void Map::Init(string name) {
    if (!tilemap.load(basePath + name)) {
        cout << "Failed to load tilemap." << endl;
    }

    tilemapTexture = TextureManager::GetTexture("IsometricTiles.png");

    if (tilemapTexture.id != 0) {
        numTileRows = tilemapTexture.height / tileHeight;
        numTileCols = tilemapTexture.width / tileWidth;
    }
}

void Map::Draw() {
    
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

                int row = currTileNum / tileLayerCols;
                int col = currTileNum % tileLayerCols;
                float destX = (col - row) * (tileWidth / 2.0f);
                float destY = (col + row) * (tileHeight / 4.0f);

                Rectangle destRect = {destX, destY, (float)tileWidth, (float)tileHeight};

                Vector2 origin = {tileWidth / 2.0f, tileHeight / 2.0f};

                DrawTexturePro(tilemapTexture, sourceRect, destRect, origin, 0.0f, WHITE);

                currTileNum++;
            }
        }
    }
}