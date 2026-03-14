# Circa

## Requirements
- Raylib: [Install Raylib](https://github.com/raysan5/raylib)
- Ensure raylib static libraries are placed in the `libraries/` directory:
  - `libraylib-macos.a` for macOS
  - `libraylib-win.a` for Windows

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
Generates `bin/circa-win`.

## Running (macOS)
```bash
make run-macos
```
Or directly: `./bin/circa-macos`

## Build and Run (macOS)
```bash
make build-run-macos
```

## Formatting
```bash
make format
```
Formats source files with clang-format.