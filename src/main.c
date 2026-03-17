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
	Vector2 mousePositions[MAX];
	Color color;
};

struct ColorMap Colors[5] = {
    {"Blue", BLUE},   {"Purple", PURPLE}, {"DarkGray", DARKGRAY},
    {"Black", BLACK}, {"White", WHITE},
};

void paintAll(Vector2 mousePositions[MAX], Color color) {
  // Draw our "brush strokes"
  for (int i = 0; i < MAX; i++) {
    Vector2 pos = mousePositions[i];
    if (pos.x > 0 && pos.y > 0) {
      DrawCircleV(pos, 10.0, color);
    }
  }
}

void drawPoints(Vector2 mousePositions[MAX], int *idx, bool mouseButtonDown,
                Color color) {
  Vector2 MousePosition = GetTouchPosition(0);

  printf("----> <%f, %f>\n", MousePosition.x, MousePosition.y);

  DrawCircle(MousePosition.x, MousePosition.y, 10.0, RED);

  if (mouseButtonDown) {
    if (MousePosition.x >= 0) {
      mousePositions[*idx] = MousePosition;
      *idx += 1;
    }
  }

  paintAll(mousePositions, color);
}

void reset(Vector2 mousePositions[MAX], int *idx) {
  for (int i = 0; i < MAX; i++) {
    Vector2 v = {-1, -1};
    mousePositions[i] = v;
  }
  *idx = 0;
}

// TODO: Track all the mouse positions, and their corresponding colors at that time
int main(void) {
  InitWindow(1600, 1200, "CIRCA");

  ToggleFullscreen();
  // SetWindowState(FLAG_WINDOW_RESIZABLE);
  // MaximizeWindow();

  // NOTE: Mouse position tracking only works with fullscreen for now.
  // ToggleFullscreen(); // TODO: For some reason, partial dimensions or sub-max
  // dimensions do not work in macos, not allowing it to paint.

  SetTargetFPS(1000);

  Vector2 mousePositions[MAX] = {};
  int idx = 0;
  bool shouldClear = false;
  Color currentColor = BLUE; // Default to blue

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
    DrawText("Select Color:", 190, 320, 20, LIGHTGRAY);

    // Clear button with neutral background
    if (GuiButton((Rectangle){190, 350, 200, 50}, "Clear")) {
      shouldClear = true;
    }
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

    // Color selection buttons with adjusted positions and borders
    for (int i = 0; i < NUM_OF_COLORS; i++) {
      GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, ColorToInt(Colors[i].color));
      if (GuiButton((Rectangle){190, 410 + 60 * i, 200, 50}, Colors[i].name)) {
        currentColor = Colors[i].color;
      }
    }

    if (shouldClear) {
      reset(mousePositions, &idx);
      shouldClear = false;
    }

    if (mouseButtonDown) {
      DrawText("DRAWING...", 190, 100, 20, LIGHTGRAY);
    }
    drawPoints(mousePositions, &idx, mouseButtonDown, currentColor);

    EndDrawing();
  }

  CloseWindow();
}
