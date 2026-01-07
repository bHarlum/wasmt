# Task 01: Basic Functions (Hello WASM)

## Goal

Create a simple C++ function that adds two numbers and compile it to WebAssembly so it can be called from JavaScript.

## Concepts You'll Learn

- Function syntax in C++
- Parameters and return types
- `extern "C"` linkage
- `EMSCRIPTEN_KEEPALIVE` macro
- Basic WASM compilation with Emscripten

See [LEARNING.md](../LEARNING.md#task-01-basic-functions) for detailed explanations.

## Requirements

Create `src/math_ops.cpp` with the following function:

### Function: `add(int a, int b)`

**Signature:**
```cpp
int add(int a, int b)
```

**Behavior:**
- Takes two integer parameters
- Returns their sum
- Must be callable from JavaScript (use `extern "C"` and `EMSCRIPTEN_KEEPALIVE`)

## Unit Tests

The tests in `tests/unit/test_task01.cpp` expect:

- `add(2, 3)` returns `5`
- `add(-1, 1)` returns `0`
- `add(100, 200)` returns `300`

Run with:
```bash
make build-unit-task01
make test-unit-task01
```

## Integration Tests

The tests in `tests/integration/test_task01.html` verify:

- WASM module loads successfully
- `add()` function is callable from JavaScript
- `add(5, 7)` returns `12` in the browser

Run with:
```bash
make build-wasm-task01
make serve
# Open http://localhost:8000/tests/integration/test_task01.html
```

## Files to Create

- `src/math_ops.cpp` - Your implementation

## Hints

1. Include the Emscripten header: `#include <emscripten/emscripten.h>`
2. Use `extern "C"` to prevent name mangling
3. Use `EMSCRIPTEN_KEEPALIVE` before the function to export it
4. The function body is straightforward - just return the sum

## Success Criteria

- [ ] All unit tests pass
- [ ] Code compiles without warnings
- [ ] WASM module builds successfully
- [ ] All integration tests pass in browser
- [ ] You understand `extern "C"` and why it's needed
- [ ] You understand what EMSCRIPTEN_KEEPALIVE does

## Next Steps

Once all tests pass, move on to [TASK_02.md](TASK_02.md) to learn about string handling!
