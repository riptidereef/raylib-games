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
}

void Game::Update() {
    BeginDrawing();
    ClearBackground(SKYBLUE);

    //DrawFPS(0, 0);

    if (IsKeyPressed(KEY_A)) {
        PrintMap();
    }

    DrawMap();

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
}


