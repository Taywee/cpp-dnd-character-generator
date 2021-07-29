.PHONY: all
all:
	cmake -S. -Bbuild
	cmake --build build
