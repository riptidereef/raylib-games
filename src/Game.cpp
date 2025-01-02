#include "Game.h"

void Game::Init() {
    screenWidth = 640;
    screenHeight = 360;
    tileSize = 20;

    tileColors.push_back(Color({20, 20, 20, 255}));
    tileColors.push_back(Color({255, 255, 255, 255}));
    tileColors.push_back(Color({225, 225, 225, 255}));
    tileColors.push_back(Color({195, 195, 195, 255}));
    tileColors.push_back(Color({166, 166, 166, 255}));
    tileColors.push_back(Color({138, 138, 138, 255}));
    tileColors.push_back(Color({111, 111, 111, 255}));
    tileColors.push_back(Color({86, 86, 86, 255}));
    tileColors.push_back(Color({61, 61, 61, 255}));
    tileColors.push_back(Color({46, 46, 46, 255}));

    InitWindow(screenWidth, screenHeight, "Window");
    SetTargetFPS(targetFPS);

    ReadMap("./data/maps/01.txt");

    camera = {0};
    camera.target = {cameraTarget.x, cameraTarget.y};
    camera.offset = {screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void Game::Update() {

    camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
    if (camera.zoom > 3.0f) {
        camera.zoom = 3.0f;
    }
    else if (camera.zoom < 0.1f) {
        camera.zoom = 0.1f;
    }

    if (IsKeyDown(KEY_A)) {
        cameraTarget.x -= 5.0;
    }
    else if (IsKeyDown(KEY_D)) {
        cameraTarget.x += 5.0;
    }

    if (IsKeyDown(KEY_W)) {
        cameraTarget.y -= 5.0;
    }
    else if (IsKeyDown(KEY_S)) {
        cameraTarget.y += 5.0;
    }

    camera.target = {cameraTarget.x, cameraTarget.y};
    

    if (IsKeyPressed(KEY_M)) {
        PrintMap();
    }

    BeginDrawing();
    ClearBackground(SKYBLUE);
    BeginMode2D(camera);

        DrawMap();

    EndMode2D();
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

    string line;
    if (getline(mapFile, line)) {
        int commaPos = line.find(',');

        string rowString = line.substr(0, commaPos);
        string colString = line.substr(commaPos + 1);line.substr(commaPos + 1);

        numRows = stoi(rowString);
        numCols = stoi(colString);
    }
    else {
        cout << "Error reading map dimensions." << endl;
    }

    cout << "Map Size: (" << numRows << ", " << numCols << ")" << endl;

    for (int i = 0; i < numRows; i++) {

        getline(mapFile, line);
        
        vector<int> currRow;
        for (int j = 0; j < numCols; j++) {
            char currTile = line[j];
            
            if (currTile == 'Z') {
                currRow.push_back(1);
                start = make_pair(i, j);
            }
            else if (currTile == 'X') {
                currRow.push_back(1);
                finish = make_pair(i, j);
            }
            else {
                currRow.push_back(currTile - '0');
            }
        }
        mapGrid.push_back(currRow);
    }

    cameraTarget = {(numCols * tileSize) / 2.0f, (numRows * tileSize) / 2.0f};
}

void Game::PrintMap() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << mapGrid[i][j] << " ";
        }
        cout << endl;
    }
}

void Game::DrawMap() {

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {

            if ((i == start.first && j == start.second)) {
                DrawRectangle(j * tileSize, i * tileSize, tileSize, tileSize, GREEN);
            }
            else if ((i == finish.first && j == finish.second)) {
                DrawRectangle(j * tileSize, i * tileSize, tileSize, tileSize, BLUE);
            }
            else {
                int tileWeight = mapGrid[i][j];
                DrawRectangle(j * tileSize, i * tileSize, tileSize, tileSize, tileColors[tileWeight]);
            }
        }
    }

    //DrawCircle(cameraTarget.x, cameraTarget.y, 5, RED);
}


