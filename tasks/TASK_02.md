# Task 02: Strings

## Goal

Work with string parameters and return values, learning about C-style strings (`char*`), memory management, and string lifetime.

## Concepts You'll Learn

- C-style strings (`char*`)
- `std::string` class
- Memory allocation and deallocation
- String lifetime management
- Pointers and memory ownership

See [LEARNING.md](../LEARNING.md#task-02-strings) for detailed explanations.

## Requirements

Create `src/string_ops.cpp` with the following functions:

### Function: `greet(const char* name)`

**Signature:**
```cpp
const char* greet(const char* name)
```

**Behavior:**
- Takes a name as a C-style string parameter
- Returns a greeting string: `"Hello, [name]!"`
- Example: `greet("World")` returns `"Hello, World!"`
- Must manage string memory correctly
- Must be callable from JavaScript

### Function: `get_greeting_length(const char* name)`

**Signature:**
```cpp
int get_greeting_length(const char* name)
```

**Behavior:**
- Takes a name as parameter
- Returns the length of the greeting that would be generated
- Example: `get_greeting_length("Test")` returns `12` (for "Hello, Test!")
- Should not crash on empty or null input

## Unit Tests

The tests in `tests/unit/test_task02.cpp` expect:

- `greet("World")` returns `"Hello, World!"`
- `greet("Bryce")` returns `"Hello, Bryce!"`
- `get_greeting_length("Test")` returns `12`

Run with:
```bash
make build-unit-task02
make test-unit-task02
```

## Integration Tests

The tests in `tests/integration/test_task02.html` verify:

- WASM module loads successfully
- `greet()` works from JavaScript
- `greet("JavaScript")` returns correct value
- `get_greeting_length()` works correctly
- Memory is managed properly (no leaks)

Run with:
```bash
make build-wasm-task02
make serve
# Open http://localhost:8000/tests/integration/test_task02.html
```

## Files to Create

- `src/string_ops.cpp` - Your implementation

## Hints

1. For `greet()`, you need to construct a new string and return it
2. Consider using `std::string` internally for easier manipulation
3. Think about string lifetime - who owns the returned memory?
4. Static buffers or string literals can help avoid memory management issues
5. Don't forget `extern "C"` and `EMSCRIPTEN_KEEPALIVE`
6. Include headers: `<emscripten/emscripten.h>`, `<string>`, `<cstring>`

## Common Pitfalls

- Returning a pointer to a local array (undefined behavior!)
- Memory leaks from allocated strings
- Not handling null/empty input
- String not null-terminated

## Success Criteria

- [ ] All unit tests pass
- [ ] Code compiles without warnings
- [ ] WASM module builds successfully
- [ ] All integration tests pass in browser
- [ ] You understand the difference between `char*` and `std::string`
- [ ] You understand string lifetime and memory ownership

## Next Steps

Once all tests pass, move on to [TASK_03.md](TASK_03.md) to learn about arrays and memory!
