#include <raylib.h>
#include "game.h"
using namespace std;

int main(void) {
    Game game;

    game.Init();

    while (!WindowShouldClose()) {
        game.Update();
    }

    game.Shutdown();

    return 0;
}
