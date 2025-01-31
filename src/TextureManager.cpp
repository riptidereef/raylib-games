#include "TextureManager.h"

unordered_map<string, Texture2D> TextureManager::textures;
string basePath = "../data/textures/";

Texture2D TextureManager::GetTexture(const string& textureName) {

    auto it = textures.find(textureName);
    
    if (it != textures.end()) {
        return it->second;
    }
    else {

        string fullPath = basePath + textureName;
        Texture2D texture = LoadTexture(fullPath.c_str());

        if (texture.id == 0) {
            cerr << "Failed to load texture: " << textureName << endl;
        }

        textures[textureName] = texture;

        return texture;
    }
}

void TextureManager::RemoveTexture(const string& textureName) {
    auto it = textures.find(textureName);

    if (it == textures.end()) {
        cout << "Could not find texture: " << textureName << endl;
        return;
    }
    else {
        UnloadTexture(it->second);
        textures.erase(it);
        cout << "Texture " << textureName << " removed successfully." << endl;
    }
}

void TextureManager::UnloadAll() {
    for (auto& pair : textures) {
        UnloadTexture(pair.second);
    }
    textures.clear();
}