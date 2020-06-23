all: format-check

setup:
	godot --gdnative-generate-json-api api.json
	# cd godot-cpp && scons platform=linux generate_bindings=yes bits=64 target=release -j 4 && cd -
	cd godot-cpp && scons platform=linux generate_bindings=yes use_custom_api_file=yes custom_api_file=../api.json bits=64 target=release -j 4 && cd -

build:
	scons platform=linux target=release -j 4

format-check:
	clang-format --style=file --dry-run -Werror src/*.[ch]pp
