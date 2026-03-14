#include <stdio.h>
#include <unistd.h>

#include "../libraries/raylib/src/raylib.h"


int main(void)
{
    InitWindow(800, 450, "CIRCA");
	// TODO: Cannot track the mouse on partial sized displays, i.e non-fullscreen displays
	// SetWindowSize(1600, 1200);

	// NOTE: Mouse position tracking only works with fullscreen for now.
	ToggleFullscreen();

	SetTargetFPS(60);

	int MAX = 100;

	Vector2 mousePositions[100] = {0};

	int idx = 0;


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GRAY);
			Vector2 MousePosition = GetMousePosition();
			printf("----> <%f, %f>\n", MousePosition.x, MousePosition.y);
			DrawCircle(MousePosition.x, MousePosition.y, 10.0, RED);
			
			bool mousePositionDown = IsMouseButtonDown(1);
			bool mousePositionReleased = IsMouseButtonReleased(1);
			bool maxObtained = idx == MAX;


            DrawText("CIRCA", 190, 200, 60, LIGHTGRAY);

			if(idx < MAX){
				if(MousePosition.x > 0){
					mousePositions[idx] = MousePosition;
					printf("IDX --> %d", idx);
					idx += 1;
				}
			}

			if(maxObtained) {
				DrawText("MAX OBTAINED", 190, 300, 60, LIGHTGRAY);

				for(int i = 0; i < MAX; i++){
					Vector2 pos = mousePositions[i];
					int py = 300 + (10 * i+1);
					// DrawPixelV(pos, BLUE);
					DrawCircleV(pos, 10.0, RED);
					// Vector2 v = {0, 0};
					// mousePositions[i] =  v;
				}

				// idx = 0;
			}
        EndDrawing();
    }

    CloseWindow();
}
