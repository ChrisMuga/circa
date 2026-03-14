#include <stdio.h>
#include <unistd.h>

#include "../libraries/raylib/src/raylib.h"

int MAX = 100;

void drawPoints(Vector2 mousePositions[100], int *idx) {
  Vector2 MousePosition = GetTouchPosition(0);
  printf("----> <%f, %f>\n", MousePosition.x, MousePosition.y);
  DrawCircle(MousePosition.x, MousePosition.y, 10.0, RED);
  int maxObtained = *idx == MAX;

  if (*idx < MAX) {
    if (MousePosition.x > 0) {
      mousePositions[*idx] = MousePosition;
      printf("IDX --> %d", *idx);
      *idx += 1;
    }
  }

  if (maxObtained) {
    DrawText("MAX OBTAINED", 190, 300, 60, LIGHTGRAY);

    for (int i = 0; i < MAX; i++) {
      Vector2 pos = mousePositions[i];
      int py = 300 + (10 * i + 1);
      DrawCircleV(pos, 10.0, RED);
    }
  }
}

void reset(Vector2 mousePositions[100], int *idx) {
  for (int i = 0; i < MAX; i++) {
    Vector2 v = {0, 0};
    mousePositions[i] = v;
  }
  idx = 0;
}

int main(void) {
  InitWindow(800, 450, "CIRCA");
  // TODO: Cannot track the mouse on partial sized displays, i.e non-fullscreen
  // displays SetWindowSize(1600, 1200);

  // NOTE: Mouse position tracking only works with fullscreen for now.
  ToggleFullscreen();

  SetTargetFPS(60);

  Vector2 mousePositions[100] = {0};
  int idx = 0;

  while (!WindowShouldClose()) {
    bool mouseButtonDown = IsMouseButtonDown(0);
    int keyPressed = GetKeyPressed();

    if (keyPressed == KEY_BACKSPACE) {
      reset(mousePositions, &idx);
    }

    BeginDrawing();
    ClearBackground(GRAY);
    DrawText("CIRCA", 190, 200, 60, LIGHTGRAY);

    if (mouseButtonDown) {
      DrawText("DRAWING...", 190, 100, 60, LIGHTGRAY);
      drawPoints(mousePositions, &idx);
    } else {
      idx = 0;
    }

    EndDrawing();
  }

  CloseWindow();
}
