#pragma once
#include "raylib.h"

typedef struct {
  Vector2 pos;
  Texture2D body_sprite;
  Texture2D head_sprite;
} Pipe;

Pipe* InitializePipe();
void DrawPipe(Pipe *pipe);
void UpdatePipe(Pipe *pipe); 