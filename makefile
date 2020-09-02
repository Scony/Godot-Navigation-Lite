all: format-check

init:
	git submodule update --init --recursive

setup-linux:
	cd godot-cpp && scons -j$(shell nproc) platform=linux target=release generate_bindings=yes && cd ..

setup-windows:
	cd godot-cpp && scons  -j$(shell nproc) platform=windows target=release generate_bindings=yes && cd ..

build-linux:
	scons -j$(shell nproc) platform=linux target=release

build-windows:
	scons -j$(shell nproc) platform=windows target=release
	mv bin/win64/libnavigation.so bin/win64/libnavigation.dll

format-check:
	clang-format --style=file --dry-run -Werror src/*.[ch]pp
