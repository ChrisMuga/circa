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
This builds `bin/circa-macos` and runs it in fullscreen (1000 FPS). Rebuild after code changes to update binary.

## Usage

### App Workflow
- The application opens in a resizable maximized window (1600x1200, 1000 FPS) titled "CIRCA" for best mouse/touch tracking.
- A circle cursor in the current color follows the current mouse or primary touch position continuously.
- A vertical line in the current color at x=600 separates the UI panel from the drawing canvas (x > 610).
- Hold the left mouse button (checked via IsMouseButtonDown) while moving to capture positions: positions (x > 0, y > 0) are stored when holding the left mouse button; points in the drawing area (x > 610) are drawn as a circle trail in the current color (up to 10,000 points max; points outside the drawing area are stored but not drawn).
- During capture, "DRAWING..." is displayed in the top-left.
- Initial instructions: "Hold left click to start drawing..." and app title.
- Use the "Clear" GUI button (styled with 20px text size) or press Backspace to reset stored points and clear the canvas.
- Stored points in the current color (default: blue) persist after releasing the mouse until reset.

- The canvas background is gray; drawing occurs in the main area.
- Close the window (ESC or platform-specific shortcut; fullscreen may need Alt+Enter or similar).

Note: Input mixes mouse button checks with GetTouchPosition(0), optimized for touch devices but works with mouse. TODO items in code include adding icons to the Clear button and distinguishing drawing vs. viewing modes more clearly.

## Troubleshooting
- Window Issues: If input fails, adjust window state in main.c and rebuild.
- Drawing Artifacts: Invalid points (negatives) are skipped; reset clears any issues.
- Performance: 1000 FPS targets smoothness but may cap to hardware; reduce in code if needed.
