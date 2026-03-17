# Circa

A simple drawing application built with Raylib and Raygui. Capture mouse or touch positions to draw trails on the canvas.

## Requirements
- Raylib: [Install Raylib](https://github.com/raysan5/raylib)
- Ensure raylib static libraries are placed in the `libraries/` directory:
  - `libraylib-macos.a` for macOS
  - `libraylib-win.a` for Windows (ensure include path: libraries/raylib-5.5_win64_mingw-w64/include)

## Building

### macOS
```bash
make build-macos
```
Generates `bin/circa-macos`.

### Windows
```bash
make build-win
```
Generates `bin/circa-win.exe`.

## Running

### macOS
```bash
make run-macos
```
Or directly: `./bin/circa-macos`

### Windows
```bash
make run-win
```
Or directly: `bin/circa-win.exe`

## Build and Run

### macOS
```bash
make build-run-macos
```

### Windows
```bash
make build-run-win
```

## Usage

### App Workflow
- The application opens a resizable window (maximized by default) titled "CIRCA" at 1600x1200 resolution, targeting 240 FPS.
- A red circle follows the current mouse or touch position at all times.
- Hold the left mouse button (or equivalent touch input) to capture positions: stored points are drawn as green circles (up to 10,000 points).
- When drawing, "DRAWING..." is displayed.
- If 10,000 points are reached, "MAX OBTAINED" and a clear instruction appear; all stored points are redrawn in green, but no more can be added until cleared.
- Use the "Clear" button or press Backspace to reset the canvas and stored points.
- Mouse positions are printed to the console for debugging.
- Close the window (ESC or platform-specific) to exit.

Note: Fullscreen mode is recommended for accurate mouse/touch tracking (currently commented in code).

## Formatting
```bash
make format
```
Formats source files with clang-format.