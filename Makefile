build-macos:
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL libraries/libraylib-macos.a src/main.c -o bin/circa-macos
	@ echo Build generated at bin/circa
build-win:
	g++ libraries/libraylib-win.a src/main.c -o bin/circa-win
	@ echo Build generated at bin/circa
run-macos:
	@ ./bin/circa-macos
build-run-macos:
	@ make build-macos
	@ echo "Running..."
	@ make run-macos
