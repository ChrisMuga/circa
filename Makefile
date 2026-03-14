build-macos:
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraries/libraylib-macos.a src/main.c -o bin/circa
	@ echo Build generated at bin/circa
build-win:
	g++ libraries/libraylib-win.a src/main.c -o bin/circa
	@ echo Build generated at bin/circa
run:
	@ ./bin/circa
build-run:
	@ make build-macos
	@ echo "Running..."
	@ make run
