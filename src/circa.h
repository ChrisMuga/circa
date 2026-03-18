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

const struct ColorMap COLORS[5] = {
    {"Blue", BLUE},   {"Purple", PURPLE}, {"Dark Gray", DARKGRAY},
    {"Black", BLACK}, {"White", WHITE},
};

void paintAll(struct PointState pointStates[MAX]) {
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
