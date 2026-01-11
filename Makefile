.PHONY: all clean build test

all: build

build:
	mkdir -p build
	cd build && cmake ..
	cd build && make

clean:
	rm -rf build
	rm -f *.log

test: build
	cd build && ctest --output-on-failure
