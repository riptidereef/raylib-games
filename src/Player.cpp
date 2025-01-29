#include "Player.h"

void Player::Init() {
    position = {0.0f, 0.0f};
    velocity = {0.0f, 0.0f};

    playerTexture = LoadTexture("../data/sprites/Wolf.png");
}

void Player::Update(float dt) {

    velocity = {0.0f, 0.0f};

    if (IsKeyDown(KEY_A)) {
        velocity.x = -1.0f;
    }
    else if (IsKeyDown(KEY_D)) {
        velocity.x = 1.0f;
    }

    if (IsKeyDown(KEY_W)) {
        velocity.y = -1.0f;
    }
    else if (IsKeyDown(KEY_S)) {
        velocity.y = 1.0f;
    }

    if (Vector2Length(velocity) > 0) {
        velocity = Vector2Normalize(velocity);
    }

    position = Vector2Add(position, Vector2Scale(velocity, moveSpeed * dt));

    Rectangle sourceRect = {
        0.0f,
        0.0f,
        16.0f,
        16.0f
    };

    Rectangle destRect = {position.x, position.y, 16.0f * scale, 16.0f * scale};

    DrawTexturePro(playerTexture, sourceRect, destRect, {0.0f, 0.0f}, 0.0f, WHITE);
}

void Player::Shutdown() {

}