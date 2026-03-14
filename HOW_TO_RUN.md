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
- The app opens in fullscreen mode.
- A red circle follows the mouse/touch position continuously.
- The app automatically captures and stores up to 1000 positions over time, redrawing all stored points as red circles at their original locations.
- Hold the left mouse button to display "DRAWING..." status (does not affect storage).
- When 1000 points are reached, it displays "MAX OBTAINED" and "<Press Backspace to clear canvas>".
- Press Backspace at any time to reset all stored points and clear the canvas.
- Close the window (ESC or Alt+F4) to exit.