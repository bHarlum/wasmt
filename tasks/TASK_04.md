# Task 04: Classes and OOP

## Goal

Learn object-oriented programming in C++ by creating a simple class, and learn how to expose classes to JavaScript using Emscripten's Embind library.

## Concepts You'll Learn

- Class definition and syntax
- Constructors and destructors
- Member functions and variables
- Access modifiers (public/private)
- The `this` pointer
- Embind library for exporting classes to JavaScript

See [LEARNING.md](../LEARNING.md#task-04-classes-and-oop) for detailed explanations.

## Requirements

Create `src/counter.cpp` and `src/counter.h` with a `Counter` class:

### Class: `Counter`

**Members:**

```cpp
class Counter {
public:
    Counter(int initial_value);  // Constructor
    void increment();            // Increment by 1
    void decrement();            // Decrement by 1
    int get_value() const;       // Get current value
    void reset();                // Reset to 0

private:
    int value;                   // Current counter value
};
```

**Behavior:**
- Constructor sets initial value
- `increment()` adds 1 to value
- `decrement()` subtracts 1 from value
- `get_value()` returns current value
- `reset()` sets value to 0
- Each instance maintains separate state

## Unit Tests

The tests in `tests/unit/test_task04.cpp` expect:

- Can create `Counter` with initial value of 10
- `increment()` increases value correctly
- `decrement()` decreases value correctly
- `reset()` sets value to 0
- Multiple instances maintain separate state

Run with:
```bash
make build-unit-task04
make test-unit-task04
```

## Integration Tests

The tests in `tests/integration/test_task04.html` verify:

- Can create `Counter` from JavaScript using `new Module.Counter(10)`
- Can call methods: `counter.increment()`, `counter.getValue()`
- Multiple instances work independently
- Embind bindings work correctly

Run with:
```bash
make build-wasm-task04
make serve
# Open http://localhost:8000/tests/integration/test_task04.html
```

## Files to Create

- `src/counter.h` - Class declaration
- `src/counter.cpp` - Class implementation and Embind bindings

## Hints

### Header File (counter.h)
1. Use include guards: `#ifndef`, `#define`, `#endif`
2. Declare the class with public and private sections
3. Declare all member functions

### Implementation File (counter.cpp)
1. Include the header: `#include "counter.h"`
2. Include Embind: `#include <emscripten/bind.h>`
3. Implement each member function: `ReturnType Counter::function_name(...) { }`
4. Use member initializer list in constructor: `Counter::Counter(int val) : value(val) { }`
5. Add Embind bindings at the end

### Embind Bindings
```cpp
EMSCRIPTEN_BINDINGS(counter_module) {
    emscripten::class_<Counter>("Counter")
        .constructor<int>()
        .function("methodName", &Counter::methodName);
}
```

## Common Pitfalls

- Forgetting to include the header in the .cpp file
- Not using `::` scope resolution operator for implementations
- Mixing up constructor syntax
- Forgetting to bind all methods in Embind
- Method names in JavaScript are case-sensitive

## Class Design Notes

### Const Correctness
- `get_value() const` - the `const` means this method doesn't modify the object
- Use `const` for getter methods that only read data

### Encapsulation
- `private:` members can only be accessed within the class
- `public:` members can be accessed from anywhere
- This protects internal state from invalid modifications

## Success Criteria

- [ ] All unit tests pass
- [ ] Code compiles without warnings
- [ ] WASM module builds successfully
- [ ] All integration tests pass in browser
- [ ] You understand class structure (public/private)
- [ ] You understand constructors and member functions
- [ ] You can explain how Embind exports classes to JavaScript

## Next Steps

Once all tests pass, move on to [TASK_05.md](TASK_05.md) for a practical JSON parsing application!
