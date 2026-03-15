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
- The app opens in fullscreen mode (mouse/touch tracking works best here).
- Hold the left mouse button (or touch) to draw: displays "DRAWING..." and captures positions as red circles.
- Positions are stored continuously while drawing, up to 10000 points.
- Once 10000 points are reached (while drawing), it displays "MAX OBTAINED" and redraws all stored points at their original locations.
- Press Backspace at any time to reset all stored points and clear the canvas.
- Release mouse/touch to stop capturing (stored points persist until reset or max redraw).
- Close the window (ESC or Cmd+Q on macOS) to exit.
