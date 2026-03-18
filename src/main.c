#include <stdio.h>

#include "../libraries/raylib/src/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../libraries/raygui.h"

#define MAX 10000
#define NUM_OF_COLORS 5

struct ColorMap {
  char name[10];
  Color color;
};

struct PointState {
  Vector2 mousePosition;
  Color color;
};

struct ColorMap Colors[5] = {
    {"Blue", BLUE},   {"Purple", PURPLE}, {"Dark Gray", DARKGRAY},
    {"Black", BLACK}, {"White", WHITE},
};

void paintAll(struct PointState pointStates[MAX]) {
  // Draw our "brush strokes"
  for (int i = 0; i < MAX; i++) {
    struct PointState ps = pointStates[i];
    if (ps.mousePosition.x > 0 && ps.mousePosition.y > 0) {
      DrawCircleV(ps.mousePosition, 10.0, ps.color);
    }
  }
}

void drawPoints(struct PointState *pointStates, int *idx, bool mouseButtonDown,
                Color color) {
  Vector2 mp = GetTouchPosition(0);
  DrawCircleV(mp, 10.0, color);

  if (mouseButtonDown) {
    if (mp.x > 0 && mp.y > 0) {
      struct PointState curr = {mp, color};
      pointStates[*idx] = curr;
      *idx += 1;
    }
  }

  paintAll(pointStates);
}

void reset(struct PointState *pointStates, int *idx) {
  for (int i = 0; i < MAX; i++) {
    Vector2 v = {-1, -1};
    struct PointState ps = {v, ColorToInt(LIGHTGRAY)};
    pointStates[i] = ps;
  }
}

int main(void) {
  InitWindow(1600, 1200, "CIRCA");

  // ToggleFullscreen();
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  MaximizeWindow();

  // NOTE: Mouse position tracking only works with fullscreen for now.
  // ToggleFullscreen(); // TODO: For some reason, partial dimensions or sub-max
  // dimensions do not work in macos, not allowing it to paint.

  SetTargetFPS(1000);

  // struct Vector2 initV2 = {-1,-1};
  // struct PointState initPS = {initV2, GRAY};
  struct PointState pointStates[MAX - 1] = {};
  int idx = 0;
  bool shouldClear = false;
  Color currentColor = BLUE; // Default to blue

  while (!WindowShouldClose()) {
    bool mouseButtonDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    int keyPressed = GetKeyPressed();

    if (keyPressed == KEY_BACKSPACE) {
      reset(pointStates, &idx);
    }

    BeginDrawing();
    ClearBackground(GRAY);

    DrawText("CIRCA", 190, 200, 60, LIGHTGRAY);
    DrawText("Hold left click to start drawing...", 190, 250, 20, LIGHTGRAY);
    DrawText("Select Color:", 190, 320, 20, LIGHTGRAY);

    if (GuiButton((Rectangle){190, 350, 200, 50}, "Clear")) {
      shouldClear = true;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    for (int i = 0; i < NUM_OF_COLORS; i++) {
      GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(Colors[i].color));
      if (GuiButton((Rectangle){190, 410 + 60 * i, 200, 50}, Colors[i].name)) {
        currentColor = Colors[i].color;
      }
    }

    if (shouldClear) {
      reset(pointStates, &idx);
      shouldClear = false;
    }

    if (mouseButtonDown) {
      DrawText("DRAWING...", 190, 100, 20, LIGHTGRAY);
    }
    drawPoints(pointStates, &idx, mouseButtonDown, currentColor);

    EndDrawing();
  }

  CloseWindow();
}
