build-macos:
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraries/libraylib.a src/main.c -o bin/circa
	@ echo Build generated at bin/circa
build-win:
	g++ libraries/libraylib-win.a src/main.c -o bin/circa
	@ echo Build generated at bin/circa
test:
	# eval cc src/main.c $(pkg-config --libs --cflags raylib) -o bin/circa
	# eval cc src/main.c -framework IOKit -framework Cocoa -framework OpenGL $(pkg-config --libs --cflags raylib) -o bin/circa
run:
	@ ./bin/circa
build-run:
	@ make build
	@ echo "Running..."
	@ make run
