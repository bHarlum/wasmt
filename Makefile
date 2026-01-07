.PHONY: help clean serve
.PHONY: build-unit-task01 test-unit-task01 build-wasm-task01
.PHONY: build-unit-task02 test-unit-task02 build-wasm-task02
.PHONY: build-unit-task03 test-unit-task03 build-wasm-task03
.PHONY: build-unit-task04 test-unit-task04 build-wasm-task04
.PHONY: build-unit-task05 test-unit-task05 build-wasm-task05

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src
EMCC = emcc
EMCCFLAGS = -std=c++17 -s WASM=1

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
NATIVE_BUILD_DIR = $(BUILD_DIR)/native
WASM_BUILD_DIR = $(BUILD_DIR)/wasm

help:
	@echo "Available targets:"
	@echo "  Task 01: build-unit-task01, test-unit-task01, build-wasm-task01"
	@echo "  Task 02: build-unit-task02, test-unit-task02, build-wasm-task02"
	@echo "  Task 03: build-unit-task03, test-unit-task03, build-wasm-task03"
	@echo "  Task 04: build-unit-task04, test-unit-task04, build-wasm-task04"
	@echo "  Task 05: build-unit-task05, test-unit-task05, build-wasm-task05"
	@echo "  Utils: serve, clean"

# Task 01
build-unit-task01: $(NATIVE_BUILD_DIR)/test_task01

$(NATIVE_BUILD_DIR)/test_task01: $(TEST_DIR)/unit/test_task01.cpp $(SRC_DIR)/math_ops.cpp
	@mkdir -p $(NATIVE_BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-unit-task01: $(NATIVE_BUILD_DIR)/test_task01
	@$(NATIVE_BUILD_DIR)/test_task01

build-wasm-task01: $(WASM_BUILD_DIR)/math_ops.js

$(WASM_BUILD_DIR)/math_ops.js: $(SRC_DIR)/math_ops.cpp
	@mkdir -p $(WASM_BUILD_DIR)
	$(EMCC) $(EMCCFLAGS) $< -o $@ \
		-s EXPORTED_FUNCTIONS='["_add"]' \
		-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
		-s MODULARIZE=1 \
		-s EXPORT_NAME='MathModule'

# Task 02
build-unit-task02: $(NATIVE_BUILD_DIR)/test_task02

$(NATIVE_BUILD_DIR)/test_task02: $(TEST_DIR)/unit/test_task02.cpp $(SRC_DIR)/string_ops.cpp
	@mkdir -p $(NATIVE_BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-unit-task02: $(NATIVE_BUILD_DIR)/test_task02
	@$(NATIVE_BUILD_DIR)/test_task02

build-wasm-task02: $(WASM_BUILD_DIR)/string_ops.js

$(WASM_BUILD_DIR)/string_ops.js: $(SRC_DIR)/string_ops.cpp
	@mkdir -p $(WASM_BUILD_DIR)
	$(EMCC) $(EMCCFLAGS) $< -o $@ \
		-s EXPORTED_FUNCTIONS='["_greet","_get_greeting_length","_malloc","_free"]' \
		-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","UTF8ToString","stringToUTF8","lengthBytesUTF8"]' \
		-s MODULARIZE=1 \
		-s EXPORT_NAME='StringModule'

# Task 03
build-unit-task03: $(NATIVE_BUILD_DIR)/test_task03

$(NATIVE_BUILD_DIR)/test_task03: $(TEST_DIR)/unit/test_task03.cpp $(SRC_DIR)/array_ops.cpp
	@mkdir -p $(NATIVE_BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-unit-task03: $(NATIVE_BUILD_DIR)/test_task03
	@$(NATIVE_BUILD_DIR)/test_task03

build-wasm-task03: $(WASM_BUILD_DIR)/array_ops.js

$(WASM_BUILD_DIR)/array_ops.js: $(SRC_DIR)/array_ops.cpp
	@mkdir -p $(WASM_BUILD_DIR)
	$(EMCC) $(EMCCFLAGS) $< -o $@ \
		-s EXPORTED_FUNCTIONS='["_sum_array","_multiply_array","_create_sequence","_malloc","_free"]' \
		-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","getValue","setValue"]' \
		-s MODULARIZE=1 \
		-s EXPORT_NAME='ArrayModule' \
		-s ALLOW_MEMORY_GROWTH=1

# Task 04
build-unit-task04: $(NATIVE_BUILD_DIR)/test_task04

$(NATIVE_BUILD_DIR)/test_task04: $(TEST_DIR)/unit/test_task04.cpp $(SRC_DIR)/counter.cpp
	@mkdir -p $(NATIVE_BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-unit-task04: $(NATIVE_BUILD_DIR)/test_task04
	@$(NATIVE_BUILD_DIR)/test_task04

build-wasm-task04: $(WASM_BUILD_DIR)/counter.js

$(WASM_BUILD_DIR)/counter.js: $(SRC_DIR)/counter.cpp
	@mkdir -p $(WASM_BUILD_DIR)
	$(EMCC) $(EMCCFLAGS) $< -o $@ \
		--bind \
		-s MODULARIZE=1 \
		-s EXPORT_NAME='CounterModule'

# Task 05
build-unit-task05: $(NATIVE_BUILD_DIR)/test_task05

$(NATIVE_BUILD_DIR)/test_task05: $(TEST_DIR)/unit/test_task05.cpp $(SRC_DIR)/json_parser.cpp
	@mkdir -p $(NATIVE_BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-unit-task05: $(NATIVE_BUILD_DIR)/test_task05
	@$(NATIVE_BUILD_DIR)/test_task05

build-wasm-task05: $(WASM_BUILD_DIR)/json_parser.js

$(WASM_BUILD_DIR)/json_parser.js: $(SRC_DIR)/json_parser.cpp
	@mkdir -p $(WASM_BUILD_DIR)
	$(EMCC) $(EMCCFLAGS) $< -o $@ \
		-s EXPORTED_FUNCTIONS='["_parse_json_int","_parse_json_string","_is_valid_json","_malloc","_free"]' \
		-s EXPORTED_RUNTIME_METHODS='["ccall","cwrap","UTF8ToString","stringToUTF8","lengthBytesUTF8"]' \
		-s MODULARIZE=1 \
		-s EXPORT_NAME='JsonModule' \
		-s ALLOW_MEMORY_GROWTH=1

# Utilities
serve:
	@python -m http.server 8000

clean:
	rm -rf $(BUILD_DIR)
