#include <stdio.h>

#include "../libraries/raylib/src/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../libraries/raygui.h"

#define MAX 10000
void paintAll(Vector2 mousePositions[MAX]) {
  // Draw our "brush strokes"
  for (int i = 0; i < MAX; i++) {
    Vector2 pos = mousePositions[i];
    DrawCircleV(pos, 10.0, GREEN);
  }
}

void drawPoints(Vector2 mousePositions[MAX], int *idx, bool mouseButtonDown) {
  Vector2 MousePosition = GetTouchPosition(0);

  printf("----> <%f, %f>\n", MousePosition.x, MousePosition.y);

  DrawCircle(MousePosition.x, MousePosition.y, 10.0, RED);

  int maxObtained = *idx == MAX;

  if (maxObtained) {
    DrawText("MAX OBTAINED", 190, 300, 60, LIGHTGRAY);
    DrawText("<Press Backspace to clear canvas>", 190, 400, 20, LIGHTGRAY);

    paintAll(mousePositions);
    return;
  }

  if (mouseButtonDown) {
    if (*idx < MAX) {
      if (MousePosition.x > 0) {
        mousePositions[*idx] = MousePosition;
        *idx += 1;
      }
    }
  }

  paintAll(mousePositions);
}

void reset(Vector2 mousePositions[MAX], int *idx) {
  for (int i = 0; i < MAX; i++) {
    Vector2 v = {-100, -100};
    mousePositions[i] = v;
  }
  *idx = 0;
}

int main(void) {
  InitWindow(1600, 1200, "CIRCA");

  SetWindowState(FLAG_WINDOW_RESIZABLE);
  MaximizeWindow();

  // NOTE: Mouse position tracking only works with fullscreen for now.
  // ToggleFullscreen(); // TODO: For some reason, partial dimensions or sub-max
  // dimensions do not work in macos, not allowing it to paint.

  SetTargetFPS(240);

  Vector2 mousePositions[MAX] = {};
  int idx = 0;
  bool shouldClear = false;

  while (!WindowShouldClose()) {
    bool mouseButtonDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    int keyPressed = GetKeyPressed();

    if (keyPressed == KEY_BACKSPACE) {
      reset(mousePositions, &idx);
    }

    BeginDrawing();
    ClearBackground(GRAY);

    DrawText("CIRCA", 190, 200, 60, LIGHTGRAY);
    DrawText("Hold left click to start drawing...", 190, 250, 20, LIGHTGRAY);

    // TODO: How do we add icons to GuiButton?
    if (GuiButton((Rectangle){190, 280, 200, 80}, "Clear")) {
      shouldClear = true;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    if (shouldClear) {
      reset(mousePositions, &idx);
      shouldClear = false;
    }

    // TODO: When we stop holding the left click, we should find a way to simply
    // draw the mouse positions without adding to mouse positions,
    // - perhaps we will have to pass a boolean to denote "viewing mode", vs
    // "drawing mode"
    if (mouseButtonDown) {
      DrawText("DRAWING...", 190, 100, 20, LIGHTGRAY);
    }
    drawPoints(mousePositions, &idx, mouseButtonDown);

    EndDrawing();
  }

  CloseWindow();
}
