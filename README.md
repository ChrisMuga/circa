# Circa

A simple drawing application built with Raylib and Raygui. Capture mouse or touch positions to draw trails on the canvas. Opens in resizable maximized window with 1000 FPS target for smooth tracking.

## Requirements
- Raylib: [Documentation](https://www.raylib.com/) | [Repository](https://github.com/raysan5/raylib) (install via instructions there)
- Raygui: [Documentation](https://github.com/raysan5/raygui) (included in Raylib)
- Ensure raylib static libraries are placed in the `libraries/` directory:
  - `libraylib-macos.a` for macOS
  - `libraylib-win.a` for Windows (ensure include path: libraries/raylib-5.5_win64_mingw-w64/include)

## Building

### macOS
```bash
make build-macos
```
Generates `bin/circa-macos`. Rebuild after code changes to update binary with fullscreen and FPS adjustments.

### Windows
```bash
make build-win
```
Generates `bin/circa-win.exe`. Rebuild after code changes to update binary with fullscreen and FPS adjustments.

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
- The application opens in a resizable maximized window titled "CIRCA" at 1600x1200 resolution, targeting 1000 FPS for precise tracking.
- A circle in the current color follows the mouse or touch position at all times.
- Hold the left mouse button (or equivalent touch input) to capture valid positions (x > 0, y > 0): stored points are drawn as circles in the current color (up to 10,000 points; invalid positions skipped).
- When drawing, "DRAWING..." is displayed.
- Use the "Clear" button or press Backspace to reset the canvas and stored points.
- Mouse positions are printed to the console for debugging.
- Close the window (ESC or platform-specific; may require fullscreen exit shortcut).

Note: Fullscreen is now enabled by default for accurate mouse/touch tracking; adjust in code if needed.

## Formatting
```bash
make format
```
Formats source files with clang-format.