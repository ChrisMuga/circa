build-macos:
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraries/libraylib-macos.a src/main.c -o bin/circa-macos
	@ echo Build generated at bin/circa
build-win:
	zig cc -o bin/circa-win.exe src/main.c -I"libraries\raylib-5.5_win64_mingw-w64\include" "libraries\libraylib-win.a" -lopengl32 -lgdi32 -lwinmm
run-macos:
	@ ./bin/circa-macos
build-run-macos:
	@ make build-macos
	@ echo "Running..."
	@ make run-macos
format:
	@ echo Formatting files...
	@ clang-format ./src/*.c -i --verbose
