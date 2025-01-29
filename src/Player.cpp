#include "Player.h"

void Player::Init() {
    position = {0.0f, 0.0f};
    velocity = {0.0f, 0.0f};

    playerTexture = LoadTexture("../data/sprites/Wolf.png");
}

void Player::Update(float dt) {

    Rectangle sourceRect = {
        0.0f,
        0.0f,
        16.0f,
        16.0f
    };

    Rectangle destRect = {0.0f, 0.0f, 16.0f * scale, 16.0f * scale};

    DrawTexturePro(playerTexture, sourceRect, destRect, {0.0f, 0.0f}, 0.0f, WHITE);
}

void Player::Shutdown() {

}