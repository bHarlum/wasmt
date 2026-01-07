# C++ to WASM Learning Project - Complete Specification

## Project Overview

This is a test-driven learning project designed to teach C++ while building a WebAssembly (WASM) library. The project uses red/green testing - all tests start as FAILING (red), and the learner implements code to make them PASSING (green).

## Project Goals

1. **Learn C++ fundamentals** through practical implementation
2. **Understand WASM compilation** from C++ source
3. **Build a real WASM library** that runs in browsers
4. **Practice test-driven development** with clear success criteria

## Target Learner Profile

- Experienced software engineer (senior level)
- Strong background in TypeScript/JavaScript and React
- Familiar with Go and backend development
- No prior C++ experience
- Comfortable with Linux (Arch), command line, and build tools
- Prefers learning by doing with clear objectives

## Two-Layer Testing Architecture

### Layer 1: Unit Tests (C++ Native)
- **Purpose**: Fast feedback on C++ logic correctness
- **Technology**: Native C++ compilation with g++
- **Location**: `tests/unit/`
- **Run with**: `make test-unit-task01`
- **Benefits**: 
  - Quick iteration (no WASM compilation)
  - Tests pure C++ logic
  - Easy debugging
  - Can run in CI without browser

### Layer 2: Integration Tests (Browser + WASM)
- **Purpose**: Validate WASM compilation and JS interop
- **Technology**: Emscripten-compiled WASM + HTML/JavaScript
- **Location**: `tests/integration/` (HTML files)
- **Run with**: `make test-integration-task01` then open browser
- **Benefits**:
  - Tests actual artifact users consume
  - Validates browser compatibility
  - Catches WASM-specific issues
  - Tests JavaScript ↔ C++ communication

## Directory Structure

```
wasm-cpp-learning/
├── README.md                    # Project overview
├── SETUP.md                     # Installation instructions
├── QUICKSTART.md                # Get started guide
├── LEARNING.md                  # C++ concepts by task
├── Makefile                     # Build automation
├── .gitignore                   # Git ignore rules
│
├── src/                         # C++ source implementations
│   ├── math_ops.cpp            # Task 01 implementation
│   ├── string_ops.cpp          # Task 02 implementation
│   ├── array_ops.cpp           # Task 03 implementation
│   ├── counter.cpp/.h          # Task 04 implementation
│   └── json_parser.cpp/.h      # Task 05 implementation
│
├── tests/
│   ├── unit/                   # C++ unit tests (native)
│   │   ├── test_task01.cpp
│   │   ├── test_task02.cpp
│   │   ├── test_task03.cpp
│   │   ├── test_task04.cpp
│   │   └── test_task05.cpp
│   │
│   └── integration/            # Browser WASM tests
│       ├── test_task01.html
│       ├── test_task02.html
│       ├── test_task03.html
│       ├── test_task04.html
│       └── test_task05.html
│
├── build/
│   ├── native/                 # Compiled C++ tests
│   │   └── test_task01         # Executable unit test
│   │
│   └── wasm/                   # Compiled WASM artifacts
│       ├── math_ops.js         # Emscripten JS glue
│       └── math_ops.wasm       # Compiled WASM binary
│
└── tasks/                      # Task specifications
    ├── TASK_01.md             # Basic functions
    ├── TASK_02.md             # Strings
    ├── TASK_03.md             # Arrays and memory
    ├── TASK_04.md             # Classes and OOP
    └── TASK_05.md             # Real-world application
```

## Task Progression

### Task 01: Basic Functions (Hello WASM)
**Concepts**: Function syntax, parameters, return types, extern "C", EMSCRIPTEN_KEEPALIVE

**Requirements**:
- Create `add(int a, int b)` function that returns sum
- Must be callable from JavaScript

**Unit Tests**:
- ✗ add(2, 3) == 5
- ✗ add(-1, 1) == 0
- ✗ add(100, 200) == 300

**Integration Tests**:
- ✗ WASM module loads
- ✗ add() callable from JS
- ✗ add(5, 7) == 12 in browser

### Task 02: Strings
**Concepts**: char*, std::string, memory allocation, string lifetime

**Requirements**:
- `greet(const char* name)` returns "Hello, [name]!"
- `get_greeting_length(const char* name)` returns greeting length

**Unit Tests**:
- ✗ greet("World") == "Hello, World!"
- ✗ greet("Bryce") == "Hello, Bryce!"
- ✗ get_greeting_length("Test") == 12

**Integration Tests**:
- ✗ Can call greet() from JavaScript
- ✗ greet("JavaScript") works correctly
- ✗ get_greeting_length() works

### Task 03: Arrays and Memory
**Concepts**: Pointers, pointer arithmetic, arrays, WASM memory model, TypedArrays

**Requirements**:
- `sum_array(int* arr, int length)` returns sum
- `multiply_array(int* arr, int length, int multiplier)` modifies in-place
- `create_sequence(int length)` returns [0, 1, 2, ..., length-1]

**Unit Tests**:
- ✗ sum_array([1,2,3,4,5], 5) == 15
- ✗ multiply_array works correctly
- ✗ create_sequence(5) == [0,1,2,3,4]

**Integration Tests**:
- ✗ Can pass JS array to WASM
- ✗ WASM can modify array in place
- ✗ Can read WASM memory from JS

### Task 04: Classes and OOP
**Concepts**: Classes, constructors, destructors, member functions, Embind

**Requirements**:
Create `Counter` class with:
- Constructor(int initial_value)
- increment() method
- decrement() method
- get_value() method
- reset() method

**Unit Tests**:
- ✗ Can create Counter with initial value
- ✗ increment() works
- ✗ decrement() works
- ✗ reset() sets to 0
- ✗ Multiple instances maintain separate state

**Integration Tests**:
- ✗ Can create Counter from JavaScript
- ✗ Can call methods
- ✗ Multiple instances work independently

### Task 05: JSON Parser (Mini)
**Concepts**: String parsing, algorithms, error handling, practical application

**Requirements**:
Simple JSON parser for format: `{"name": "value", "age": 25}`
- `parse_json_int(const char* json, const char* key)`
- `parse_json_string(const char* json, const char* key)`
- `is_valid_json(const char* json)`

**Unit Tests**:
- ✗ Can parse integer values
- ✗ Can parse string values
- ✗ Returns error for invalid JSON
- ✗ Handles missing keys

**Integration Tests**:
- ✗ Parse JSON from JavaScript
- ✗ Handle test cases correctly
- ✗ Performance test

## Technology Stack

### Required Software
- **g++** or **clang** (C++ compiler) - version 9.0 or higher
- **Emscripten SDK** (emcc) - latest version
- **Python 3** - for local web server
- **make** - for build automation
- **git** - for version control

### Installation (Arch Linux)
```bash
# C++ compiler (likely already installed)
sudo pacman -S gcc

# Emscripten
yay -S emscripten

# Or from source:
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh

# Python (likely already installed)
sudo pacman -S python

# Make (likely already installed)
sudo pacman -S make
```

## Makefile Commands

```makefile
# Build and test workflow
make help                    # Show all commands

# Task 01 workflow (repeat for task02, task03, etc.)
make build-unit-task01       # Compile C++ unit tests
make test-unit-task01        # Run unit tests (fast)
make build-wasm-task01       # Compile to WASM
make test-integration-task01 # Info on running browser tests
make serve                   # Start web server for integration tests

# Utilities
make clean                   # Remove build artifacts
make clean-all              # Remove everything in build/
```

## Test File Format

### Unit Test Template (C++)
```cpp
// tests/unit/test_taskXX.cpp
#include <cassert>
#include <iostream>

// Forward declaration of function to test
extern "C" int add(int a, int b);

void test_add_positive() {
    assert(add(2, 3) == 5);
    std::cout << "✓ Test passed: add(2, 3) == 5" << std::endl;
}

int main() {
    std::cout << "Running Task XX Tests..." << std::endl;
    try {
        test_add_positive();
        std::cout << "All tests PASSED! ✓" << std::endl;
        return 0;
    } catch (...) {
        std::cout << "Tests FAILED! ✗" << std::endl;
        return 1;
    }
}
```

### Integration Test Template (HTML)
```html
<!DOCTYPE html>
<html>
<head>
    <title>Task XX - WASM Integration Test</title>
    <style>
        .test { margin: 10px 0; padding: 10px; }
        .pass { background: #d4edda; color: #155724; }
        .fail { background: #f8d7da; color: #721c24; }
    </style>
</head>
<body>
    <h1>Task XX: Integration Tests</h1>
    <div id="results"></div>

    <script>
        const results = document.getElementById('results');
        
        function addTest(name, passed, message) {
            const div = document.createElement('div');
            div.className = `test ${passed ? 'pass' : 'fail'}`;
            div.textContent = `${passed ? '✓' : '✗'} ${name}: ${message}`;
            results.appendChild(div);
        }

        // Load WASM module
        const script = document.createElement('script');
        script.src = '../../build/wasm/module.js';
        script.onerror = () => {
            addTest('WASM Load', false, 'Module not found - compile first');
        };
        script.onload = () => {
            Module.onRuntimeInitialized = () => {
                addTest('WASM Load', true, 'Module loaded');
                
                // Run tests here
                const result = Module._add(5, 7);
                addTest('add(5,7)', result === 12, `Got: ${result}`);
            };
        };
        document.head.appendChild(script);
    </script>
</body>
</html>
```

## Learning Resources Document

Each task should reference specific C++ concepts needed:

### Task 01 Concepts
- Function declarations and definitions
- Parameter passing (by value)
- Return types
- `extern "C"` linkage (prevents name mangling)
- EMSCRIPTEN_KEEPALIVE macro

### Task 02 Concepts
- C-style strings (char*)
- std::string class
- Memory allocation (malloc, new, delete, free)
- Pointers and memory ownership
- String lifetime management

### Task 03 Concepts
- Pointers and pointer arithmetic
- Arrays in C++
- Memory layout and alignment
- WASM linear memory model
- JavaScript TypedArrays

### Task 04 Concepts
- Class definition and syntax
- Constructors and destructors
- Member functions and variables
- Access modifiers (public/private/protected)
- `this` pointer
- Embind library for class bindings

### Task 05 Concepts
- String manipulation (find, substr)
- Parsing algorithms
- Error handling (exceptions, return codes)
- Edge case handling
- std::string methods

## Workflow Example

```bash
# Start Task 01
cd wasm-cpp-learning
cat tasks/TASK_01.md                    # Read requirements

# Try to build (will fail - no implementation yet)
make build-unit-task01
# Error: src/math_ops.cpp not found

# Create implementation file
touch src/math_ops.cpp
vim src/math_ops.cpp                    # Implement add() function

# Build and run unit tests
make build-unit-task01                  # Compile
make test-unit-task01                   # Run tests
# ✗ Tests fail - fix implementation

# Iterate until unit tests pass
vim src/math_ops.cpp
make test-unit-task01
# ✓ All unit tests pass!

# Build WASM version
make build-wasm-task01                  # Compile to WASM

# Test integration
make serve                              # Start web server
# Open http://localhost:8000/tests/integration/test_task01.html
# ✓ All integration tests pass!

# Move to Task 02
cat tasks/TASK_02.md
```

## Key Design Principles

### 1. No Solutions Provided
- Task descriptions explain WHAT to build, never HOW
- Tests show expected behavior
- Hints point to concepts, not implementations
- Learner must research and implement

### 2. Red/Green Testing
- All tests start FAILING (red)
- Success = making tests PASSING (green)
- Clear binary feedback (works or doesn't)
- No ambiguity about progress

### 3. Progressive Complexity
- Each task builds on previous concepts
- Start simple (basic functions)
- End complex (practical application)
- Natural learning curve

### 4. Two-Layer Validation
- Unit tests validate logic (fast feedback)
- Integration tests validate interop (real-world usage)
- Both must pass to complete task

### 5. Self-Contained Tasks
- Each task is independent
- Can be attempted in order
- Clear entry/exit criteria
- Modular structure

## Success Criteria

A task is complete when:
1. ✓ All unit tests pass (C++ native)
2. ✓ All integration tests pass (WASM in browser)
3. ✓ Code compiles without warnings
4. ✓ Learner understands the concepts used

## Anti-Patterns to Avoid

❌ **Don't provide solutions in task descriptions**
- Give hints, not code
- Point to concepts, not implementations

❌ **Don't make tasks too large**
- Each task should take 1-4 hours
- Break complex tasks into smaller ones

❌ **Don't skip unit tests**
- Always validate C++ logic before WASM
- Integration tests catch different issues

❌ **Don't make assumptions about prior knowledge**
- Explain what concepts are needed
- Provide learning resources

❌ **Don't test implementation details**
- Test behavior, not internal structure
- Allow multiple valid implementations

## Documentation Files to Create

### README.md
- Project overview
- Directory structure
- Quick links to other docs

### SETUP.md
- Installation instructions
- Prerequisite software
- Verification steps
- Troubleshooting

### QUICKSTART.md
- Get started in 5 minutes
- First task walkthrough
- Common commands
- Success indicators

### LEARNING.md
- C++ concepts by task
- Learning resources
- Common pitfalls
- Debugging tips
- Progress tracking checklist

### tasks/TASK_XX.md (for each task)
- Goal statement
- Concepts to learn
- Requirements (what to build)
- Unit test descriptions
- Integration test descriptions
- Hints (no solutions)
- Success criteria
- Files to create

## Implementation Notes

### Emscripten Compilation Flags

Basic function export:
```bash
emcc src/math_ops.cpp -o build/wasm/math_ops.js \
  -s EXPORTED_FUNCTIONS='["_add"]' \
  -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]'
```

With Embind (for classes):
```bash
emcc src/counter.cpp -o build/wasm/counter.js \
  --bind \
  -s MODULARIZE=1 \
  -s EXPORT_NAME='Module'
```

### C++ Function Export Pattern

```cpp
#include <emscripten/emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int add(int a, int b) {
        return a + b;
    }
}
```

### Class Export Pattern (Embind)

```cpp
#include <emscripten/bind.h>

class Counter {
public:
    Counter(int initial) : value(initial) {}
    void increment() { value++; }
    int get_value() const { return value; }
private:
    int value;
};

EMSCRIPTEN_BINDINGS(counter_module) {
    emscripten::class_<Counter>("Counter")
        .constructor<int>()
        .function("increment", &Counter::increment)
        .function("getValue", &Counter::get_value);
}
```

## Expected Timeline

- **Task 01**: 1-2 hours (learning basics)
- **Task 02**: 2-3 hours (strings are tricky)
- **Task 03**: 3-4 hours (memory concepts)
- **Task 04**: 2-3 hours (OOP and Embind)
- **Task 05**: 4-6 hours (practical application)

**Total**: ~15-20 hours for complete project

## Extensibility

After completing all 5 tasks, the project can be extended with:
- Task 06: Performance optimization
- Task 07: Threading with Web Workers
- Task 08: Binary data protocols
- Task 09: Complex data structures
- Task 10: Real-world library (choose domain)

## Context for Future Implementation

When implementing this project:
1. Start by creating directory structure
2. Generate Makefile with all commands
3. Create task description files (TASK_01.md through TASK_05.md)
4. Write failing unit tests for each task
5. Write failing integration tests for each task
6. Create documentation files (README, SETUP, QUICKSTART, LEARNING)
7. Test that build system works correctly
8. Verify tests fail initially
9. Package and deliver to learner

**Critical**: Do NOT implement the actual C++ solutions. The learner must write all code in `src/` themselves. Only provide:
- Task descriptions
- Test code (that expects implementations)
- Build system
- Documentation

## Summary

This project teaches C++ through practical WASM development using test-driven learning. Two-layer testing (unit + integration) provides fast feedback and validates both logic and interop. Tasks progress from simple functions to practical applications, with clear success criteria at each step. No solutions provided - learner implements everything, guided by failing tests.
