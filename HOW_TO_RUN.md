# How to Run Circa

## Building and Running

### Windows
```bash
make build-win
make run-win
```
This builds `bin/circa-win.exe` and runs it in fullscreen.

### macOS
```bash
make build-macos
make run-macos
```
This builds `bin/circa-macos` and runs it in fullscreen.

## Usage

### App Workflow
- The application opens a resizable, maximized window (1600x1200, 240 FPS) titled "CIRCA". Fullscreen is recommended for best mouse/touch tracking (toggle via code if needed).
- A red circle cursor follows the current mouse or primary touch position continuously.
- Hold the left mouse button (checked via IsMouseButtonDown) while moving to capture positions: each valid position (x > 0) is stored and drawn as a green circle trail (up to 10,000 points max).
- During capture, "DRAWING..." is displayed in the top-left.
- Initial instructions: "Hold left click to start drawing..." and app title.
- When 10,000 points are reached, "MAX OBTAINED" and "<Press Backspace to clear canvas>" are shown; all stored points are redrawn as green circles, but no further points can be added until reset.
- Use the "Clear" GUI button (styled with 20px text size) or press Backspace to reset stored points and clear the canvas.
- Stored green points persist after releasing the mouse until reset.
- Mouse/touch positions are printed to console (stdout) every frame for debugging.
- The canvas background is gray; drawing occurs in the main area.
- Close the window (ESC or platform-specific shortcut) to exit.

Note: Input mixes mouse button checks with GetTouchPosition(0), optimized for touch devices but works with mouse. TODO items in code include adding icons to the Clear button and distinguishing drawing vs. viewing modes more clearly.
