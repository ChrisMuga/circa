#include <stdio.h>

#include "circa.h"

// TODO: Implement this with pointer arithmetic
// TODO: Allow for an array of brush sizes
// TODO: Add exit button
// TODO: Can we "play" the drawing, maybe by remembering states and reducing the
// FPS?
// TODO: The pointer/cursor goes/hides under the painting on hover, this should
// be fixed because it messes up precision
// TODO: Implement DRAWING_LIMIT_Y on the bottom side, to avoid collision with
// the status bar
int main(void) {
  InitWindow(1600, 1200, "CIRCA");

  SetWindowState(FLAG_WINDOW_RESIZABLE);
  MaximizeWindow();

  // NOTE: Mouse position tracking only works with fullscreen for now.
  ToggleFullscreen();

  // TODO: For some reason, partial dimensions or sub-max
  // dimensions do not work in macos, not allowing it to paint.

  SetTargetFPS(1000);

  struct PointState pointStates[MAX - 1] = {};
  int idx = 0;
  bool shouldClear = false;
  Color currentColor = BLUE;

  while (!WindowShouldClose()) {
    bool mouseButtonDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    int keyPressed = GetKeyPressed();

    if (keyPressed == KEY_BACKSPACE) {
      reset(pointStates, &idx);
    }

    BeginDrawing();
    ClearBackground(GRAY);

    DrawText("CIRCA", 190, 200, 60, LIGHTGRAY);
    DrawText("Select Color:", 190, 250, 20, LIGHTGRAY);

    int renderHeight = GetRenderHeight();
    DrawRectangle(DRAWING_LIMIT_X, 0, SEPARATOR_WIDTH, renderHeight, LIGHTGRAY);

    if (GuiButton((Rectangle){190, 350, 200, 50}, "Clear")) {
      shouldClear = true;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    for (int i = 0; i < NUM_OF_COLORS; i++) {
      GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(COLORS[i].color));
      if (GuiButton((Rectangle){190, 410 + 60 * i, 200, 50}, COLORS[i].name)) {
        currentColor = COLORS[i].color;
      }
    }
    GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(WHITE));

    if (shouldClear) {
      reset(pointStates, &idx);
      shouldClear = false;
    }

    drawPoints(pointStates, &idx, mouseButtonDown, currentColor);

    EndDrawing();
  }

  CloseWindow();
}
