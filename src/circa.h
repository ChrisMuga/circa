#include "../libraries/raylib/src/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../libraries/raygui.h"

#define MAX 10000
#define NUM_OF_COLORS 8
#define DRAWING_LIMIT_X 600.0
#define LIMIT_PADDING 10
#define LIMIT_X DRAWING_LIMIT_X + LIMIT_PADDING

struct ColorMap {
  char name[10];
  Color color;
};

struct PointState {
  Vector2 mousePosition;
  Color color;
};

const struct ColorMap COLORS[NUM_OF_COLORS] = {
    {"Purple", PURPLE}, {"Dark Gray", DARKGRAY},
    {"Black", BLACK},   {"White", WHITE},
    {"Red", RED},       {"Blue", BLUE},
    {"Green", GREEN},   {"Yellow", YELLOW}};

void paintAll(struct PointState pointStates[MAX]) {
  for (int i = 0; i < MAX; i++) {
    struct PointState ps = pointStates[i];
    if (ps.mousePosition.x > 0 && ps.mousePosition.y > 0 &&
        ps.mousePosition.x > LIMIT_X) {
      DrawCircleV(ps.mousePosition, 10.0, ps.color);
    }
  }
}

void drawPoints(struct PointState *pointStates, int *idx, bool mouseButtonDown,
                Color color) {
  Vector2 mp = GetTouchPosition(0);

  char status[100] = "Circa - left click and drag to start drawing...";

  if (mouseButtonDown) {
    if (mp.x > LIMIT_X) {
      strcpy(status, "Circa - Drawing...");
    } else {
      strcpy(status, "Circa - Cannot draw here...");
    }
  }

  GuiStatusBar((Rectangle){0, 0, 2000, 50}, status);

  if (mp.x > LIMIT_X) {
    DrawCircleV(mp, 10.0, color);
  }

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
