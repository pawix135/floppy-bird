#pragma once
#include "bird.h"

typedef struct {
  Bird *bird;
  float dt;
} Game;

Game *AllocateGame();
void InitializeGame(Game* game);
void UpdateGame(Game* game);
void DrawGame(Game* game);
void FreeGame(Game* game);

