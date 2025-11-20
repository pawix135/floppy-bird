#include <stdlib.h>
#include "game.h"
#include "bird.h"
#include "raylib.h"

Game *AllocateGame(){
  Game *game = (Game*)malloc(sizeof(Game));
  if(game == NULL) return NULL;
  return game;
}

void InitializeGame(Game* game){
  game->bird = InitializeBird();
  game->dt = 0;
}

void UpdateGame(Game *game){
  game->dt = GetFrameTime();
  UpdateBird(game->bird, game->dt);
}

void DrawGame(Game *g){
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawBird(g->bird);
  DrawFPS(100, 100);
  EndDrawing();
}

void FreeGame(Game* game){
  if(game == NULL) return;

  if(game->bird != NULL){
    FreeBird(game->bird);
    game->bird = NULL;
  }
  
  free(game);
}
