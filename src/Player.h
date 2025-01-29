#pragma once
#include <raylib.h>

class Player {
    private:
        Texture2D playerTexture;
        float scale = 3.0f;

    public:
        void Init();
        void Update(float dt);
        void Shutdown();

        Vector2 position;
        Vector2 velocity;
};