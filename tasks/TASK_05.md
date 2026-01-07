# Task 05: JSON Parser (Mini)

## Goal

Build a simple JSON parser as a practical application, combining all concepts learned so far: functions, strings, memory management, and algorithms.

## Concepts You'll Learn

- String parsing and manipulation
- Parsing algorithms
- Error handling (return codes vs exceptions)
- Edge case handling
- Practical application development

See [LEARNING.md](../LEARNING.md#task-05-json-parser) for detailed explanations.

## Requirements

Create `src/json_parser.cpp` and `src/json_parser.h` with a simple JSON parser.

**Supported Format:**
```json
{"name": "value", "age": 25, "city": "Portland"}
```

Limitations:
- Only simple flat objects (no nesting)
- String values in double quotes
- Integer values (no floats)
- No arrays

### Function: `parse_json_int(const char* json, const char* key)`

**Signature:**
```cpp
int parse_json_int(const char* json, const char* key)
```

**Behavior:**
- Parses `json` and extracts integer value for `key`
- Example: `parse_json_int('{"age": 25}', "age")` returns `25`
- Returns `-1` on error (invalid JSON, key not found, etc.)

### Function: `parse_json_string(const char* json, const char* key)`

**Signature:**
```cpp
const char* parse_json_string(const char* json, const char* key)
```

**Behavior:**
- Parses `json` and extracts string value for `key`
- Example: `parse_json_string('{"name": "John"}', "name")` returns `"John"`
- Returns `nullptr` on error
- Returned string should be usable (consider lifetime)

### Function: `is_valid_json(const char* json)`

**Signature:**
```cpp
bool is_valid_json(const char* json)
```

**Behavior:**
- Validates JSON format
- Returns `true` if valid, `false` otherwise
- Checks: matching braces, proper quotes, comma separation, etc.

## Unit Tests

The tests in `tests/unit/test_task05.cpp` expect:

- `parse_json_int()` correctly extracts integer values
- `parse_json_string()` correctly extracts string values
- Returns error codes for invalid JSON
- Handles missing keys appropriately
- `is_valid_json()` correctly validates format

Run with:
```bash
make build-unit-task05
make test-unit-task05
```

## Integration Tests

The tests in `tests/integration/test_task05.html` verify:

- Can parse JSON from JavaScript
- Handles various test cases correctly
- Error handling works from JavaScript
- Performance is acceptable for simple parsing

Run with:
```bash
make build-wasm-task05
make serve
# Open http://localhost:8000/tests/integration/test_task05.html
```

## Files to Create

- `src/json_parser.h` - Function declarations
- `src/json_parser.cpp` - Implementation

## Hints

### Parsing Strategy
1. Find the key in the JSON string
2. Find the colon after the key
3. Determine value type (string vs number)
4. Extract the value
5. Return it (handling memory correctly)

### Useful std::string Methods
- `find(substring)` - find position of substring
- `substr(start, length)` - extract substring
- `c_str()` - get C-style string
- `length()` or `size()` - get string length

### Error Handling
Use return codes for simplicity:
- Return `-1` for integer errors
- Return `nullptr` for string errors
- Return `false` for validation errors

### Edge Cases to Handle
- Null or empty input
- Missing keys
- Malformed JSON (missing quotes, braces, etc.)
- Keys that appear multiple times
- Extra whitespace

## Example Parsing Approach

```cpp
// Pseudo-code for parse_json_int
1. Find the key: '"age"'
2. Find colon after key
3. Skip whitespace after colon
4. Read digits until comma or brace
5. Convert to integer (std::stoi or manual)
6. Return value
```

## Common Pitfalls

- Not handling edge cases (null, empty, malformed)
- Memory leaks in string returns
- Buffer overflows with C-style strings
- Not validating input before parsing
- Off-by-one errors in string positions

## Success Criteria

- [ ] All unit tests pass
- [ ] Code compiles without warnings
- [ ] WASM module builds successfully
- [ ] All integration tests pass in browser
- [ ] You understand string parsing techniques
- [ ] You can explain your error handling strategy
- [ ] You've handled all edge cases

## Extension Ideas (Optional)

After completing the basic requirements:
- Add support for boolean values
- Add support for null values
- Handle nested objects (one level deep)
- Add a function to extract all keys
- Improve error messages (return error codes with details)

## Next Steps

Congratulations! After completing this task, you've built a complete WASM library from scratch and learned C++ fundamentals.

Consider:
- Building your own custom WASM library for a specific domain
- Exploring more complex C++ features (templates, RAII, smart pointers)
- Optimizing your code for performance
- Adding more comprehensive error handling
