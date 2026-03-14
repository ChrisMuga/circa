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
- Hold the left mouse button (or touch on supported devices) to draw red circles at cursor positions. It stores up to 1000 points.
- Press Backspace to reset all points.
- When max points (1000) are reached, it displays "MAX OBTAINED" and redraws all stored points below the title.
- Close the window (ESC or Alt+F4) to exit.