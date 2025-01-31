#include "Tilemap.h"

void Tilemap::Init(const string& tilemapName) {
    if (!tilemap.load(basePath + tilemapName)) {
        cout << "Failed to load tilemap." << endl;
    }

    tilemapTexture = TextureManager::GetTexture("DungeonTileset.png");

    if (tilemapTexture.id != 0) {
        numTileRows = tilemapTexture.height / tileHeight;
        numTileCols = tilemapTexture.width / tileWidth;
    }
}

void Tilemap::DrawMap() {
    
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