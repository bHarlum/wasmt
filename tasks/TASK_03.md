# Task 03: Arrays and Memory

## Goal

Work with arrays and pointers, learning how memory is shared between JavaScript and WebAssembly through the WASM linear memory model.

## Concepts You'll Learn

- Pointers and pointer arithmetic
- Arrays in C++
- Memory layout and alignment
- WASM linear memory model
- JavaScript TypedArrays
- Passing arrays between JS and WASM

See [LEARNING.md](../LEARNING.md#task-03-arrays-and-memory) for detailed explanations.

## Requirements

Create `src/array_ops.cpp` with the following functions:

### Function: `sum_array(int* arr, int length)`

**Signature:**
```cpp
int sum_array(int* arr, int length)
```

**Behavior:**
- Takes a pointer to an integer array and its length
- Returns the sum of all elements
- Example: `sum_array([1,2,3,4,5], 5)` returns `15`

### Function: `multiply_array(int* arr, int length, int multiplier)`

**Signature:**
```cpp
void multiply_array(int* arr, int length, int multiplier)
```

**Behavior:**
- Takes an array, its length, and a multiplier
- Modifies the array in-place, multiplying each element
- Example: `multiply_array([1,2,3], 3, 2)` changes array to `[2,4,6]`
- Returns nothing (void)

### Function: `create_sequence(int length)`

**Signature:**
```cpp
int* create_sequence(int length)
```

**Behavior:**
- Creates and returns a new array of integers
- Array contains sequence `[0, 1, 2, ..., length-1]`
- Example: `create_sequence(5)` returns `[0,1,2,3,4]`
- Caller is responsible for freeing the memory

## Unit Tests

The tests in `tests/unit/test_task03.cpp` expect:

- `sum_array([1,2,3,4,5], 5)` returns `15`
- `sum_array([10,20,30], 3)` returns `60`
- `multiply_array()` correctly modifies array in-place
- `create_sequence(5)` creates `[0,1,2,3,4]`

Run with:
```bash
make build-unit-task03
make test-unit-task03
```

## Integration Tests

The tests in `tests/integration/test_task03.html` verify:

- Can pass JavaScript array to WASM
- WASM can read array data from JS
- WASM can modify array in-place (JS sees changes)
- Can create array in WASM and read it from JS
- Memory management works correctly

Run with:
```bash
make build-wasm-task03
make serve
# Open http://localhost:8000/tests/integration/test_task03.html
```

## Files to Create

- `src/array_ops.cpp` - Your implementation

## Hints

1. Arrays and pointers are closely related in C++
2. `arr[i]` is equivalent to `*(arr + i)`
3. For `create_sequence()`, allocate memory with `malloc()` or `new[]`
4. In WASM, JavaScript allocates memory and passes the pointer
5. Use pointer arithmetic or array indexing for iteration
6. Don't forget `extern "C"` and `EMSCRIPTEN_KEEPALIVE`

## Common Pitfalls

- Array out of bounds access
- Not checking for null pointers
- Memory leaks (allocating but not freeing)
- Off-by-one errors in loops

## Memory Management Notes

### In C++ Unit Tests:
```cpp
int* arr = create_sequence(5);
// Use the array
delete[] arr;  // Must free!
```

### In JavaScript/WASM:
```js
const length = 5;
const ptr = Module._malloc(length * 4);  // 4 bytes per int
// Use the pointer
Module._free(ptr);  // Must free!
```

## Success Criteria

- [ ] All unit tests pass
- [ ] Code compiles without warnings
- [ ] WASM module builds successfully
- [ ] All integration tests pass in browser
- [ ] You understand pointers and pointer arithmetic
- [ ] You understand how WASM shares memory with JavaScript
- [ ] You can explain the difference between stack and heap allocation

## Next Steps

Once all tests pass, move on to [TASK_04.md](TASK_04.md) to learn about classes and OOP!
