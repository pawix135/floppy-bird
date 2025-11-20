#include "raylib.h"
#include "game.h"

int main() {

  SetConfigFlags(FLAG_VSYNC_HINT);
  InitWindow(800, 450, "Window");
#ifdef DEBUG
  SetTraceLogLevel(LOG_DEBUG);
#endif

  Game *game = AllocateGame();
  InitializeGame(game); 

  while (!WindowShouldClose()) {
    UpdateGame(game);
    DrawGame(game);
  }

  FreeGame(game);
  CloseWindow();
  return 0;
}