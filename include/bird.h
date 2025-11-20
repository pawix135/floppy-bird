#pragma once
#include "raylib.h"

typedef struct {
  Vector2 pos;
  Vector2 vel;
  Texture2D sprite; 
  float rotation;
} Bird;

Bird* InitializeBird();
void DrawBird(Bird *bird);
void UpdateBird(Bird *bird, float dt);
void FreeBird(Bird *bird);
