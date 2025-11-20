#include "bird.h"
#include "assets.h"
#include "raylib.h"
#include "raymath.h"
#include "utils.h"
#include <stdlib.h>

const float GRAVITY = 1000.0f;
const float JUMP_STRENGTH = -350.0f;

Bird *InitializeBird() {
  Bird *bird = (Bird *)malloc(sizeof(Bird));
  bird->sprite = LoadTextureFromMemory(".png", bird_png, bird_png_len);
  bird->pos = (Vector2){100, 100};
  bird->vel = (Vector2){0, 1};
  bird->rotation = 0;
  return bird;
}

void DrawBird(Bird *bird) {
  Rectangle source = {0, 0, (float)bird->sprite.width,
                      (float)bird->sprite.height};
  Rectangle dest = {bird->pos.x + (float)bird->sprite.width / 2,
                    bird->pos.y + (float)bird->sprite.height / 2,
                    (float)bird->sprite.width, (float)bird->sprite.height};
  Vector2 origin = {(float)bird->sprite.width / 2,
                    (float)bird->sprite.height / 2};
  DrawTexturePro(bird->sprite, source, dest, origin, bird->rotation, WHITE);
}

void UpdateBird(Bird *bird, float dt) {

  bird->vel.y += GRAVITY * dt;

  if (IsKeyPressed(KEY_SPACE)) {
    bird->vel.y = JUMP_STRENGTH;
  }

  if (IsKeyPressed(KEY_R)) {
    bird->pos = (Vector2){100, 100};
    bird->vel = (Vector2){0, 0};
  }

  Vector2 movement = Vector2Scale(bird->vel, dt);
  bird->pos = Vector2Add(bird->pos, movement);

  if (bird->vel.y < -100) {
    bird->rotation = -25.0f;
  } else {
    bird->rotation += 100.0f * dt;
    if (bird->rotation > 90.0f) {
      bird->rotation = 90.0f;
    }
  }
}

void FreeBird(Bird *bird) {
  if (bird == NULL)
    return;
  UnloadTexture(bird->sprite);
  free(bird);
  TraceLog(LOG_DEBUG, "Bird freed");
}