build-macos:
	@ clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraries/libraylib-macos.a src/main.c -o bin/circa-macos
build-macos-debug:
	@ clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraries/libraylib-macos.a src/main.c -o bin/circa-macos -g
	@ echo Debug build generated at bin/circa-macos
debug-macos:
	@ make build-macos-debug
	@ lldb bin/circa-macos
run-macos:
	@ ./bin/circa-macos
build-run-macos:
	@ make build-macos
	@ echo "Running..."
	@ make run-macos
build-win:
	zig cc -o bin/circa-win.exe src/main.c -I"libraries\raylib-5.5_win64_mingw-w64\include" "libraries\libraylib-win.a" -lopengl32 -lgdi32 -lwinmm
run-win:
	@ ./bin/circa-win.exe
build-run-win:
	@ make build-win
	@ echo "Running..."
	@ make run-win
build-linux:
	@ gcc src/main.c -o bin/circa-linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
debug-linux:
	@ gcc src/main.c -o bin/circa-linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -g
	@ gdb bin/circa-linux
run-linux:
	@ ./bin/circa-linux
build-run-linux:
	@ make build-linux run-linux
format:
	@ echo Formatting files...
	@ clang-format ./src/*.c ./src/*.h -i --verbose
