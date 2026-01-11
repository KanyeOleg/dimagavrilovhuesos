.PHONY: all clean build debug release

BUILD_DIR = build
BUILD_TYPE ?= Debug

all: build

build:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) ..
	@cd $(BUILD_DIR) && make

debug:
	@$(MAKE) build BUILD_TYPE=Debug

release:
	@$(MAKE) build BUILD_TYPE=Release

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f *.log
