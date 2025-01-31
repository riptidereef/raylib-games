#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <raylib.h>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class TextureManager {
    private:
        static unordered_map<string, Texture2D> textures;

    public:
        static Texture2D GetTexture(const string& textureName);
        static void RemoveTexture(const string& textureName);
        static void UnloadAll();
};

#endif