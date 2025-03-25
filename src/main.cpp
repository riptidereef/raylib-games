#include <raylib.h>
#include "Game.h"

int main() {
    Game game;

    game.Init();

    while (!WindowShouldClose()) {
        game.Update(GetFrameTime());
    }

    game.Shutdown();
}