#include "utils.h"
#include "raylib.h"

Texture2D LoadTextureFromMemory(const char *ext, const void *data, int data_size){
 Image img = LoadImageFromMemory(ext, data, data_size);
 Texture2D texture = LoadTextureFromImage(img);
 UnloadImage(img); 
 return texture;
}