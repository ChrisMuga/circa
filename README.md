# Circa

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

## Formatting
```bash
make format
```
Formats source files with clang-format.