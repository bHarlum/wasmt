# C++ Learning Guide

This document explains the C++ concepts you'll learn in each task, organized for easy reference.

## Task 01: Basic Functions

### Function Declarations and Definitions

In C++, functions have a **return type**, **name**, and **parameters**:

```cpp
int add(int a, int b) {
    return a + b;
}
```

- `int` - return type
- `add` - function name
- `int a, int b` - parameters (passed by value)

### Parameter Passing (By Value)

When you pass parameters by value, C++ creates a copy:

```cpp
int add(int a, int b) {
    a = a + b;  // This modifies the local copy
    return a;
}
```

The original variables passed to `add()` remain unchanged.

### extern "C" Linkage

C++ "mangles" function names for overloading. `extern "C"` prevents this:

```cpp
extern "C" {
    int add(int a, int b) {
        return a + b;
    }
}
```

This makes the function callable from C and JavaScript.

### EMSCRIPTEN_KEEPALIVE Macro

Prevents the compiler from removing "unused" functions:

```cpp
#include <emscripten/emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int add(int a, int b) {
        return a + b;
    }
}
```

Required for functions you want to call from JavaScript.

## Task 02: Strings

### C-Style Strings (char*)

C-style strings are arrays of characters ending with null terminator `\0`:

```cpp
const char* name = "World";  // Immutable string
char buffer[20] = "Hello";   // Mutable string
```

Key points:
- `const char*` - pointer to immutable string
- Null terminator `\0` marks the end
- Manual memory management required

### std::string Class

C++ provides a string class that manages memory automatically:

```cpp
#include <string>

std::string greeting = "Hello";
greeting += " World";  // Concatenation
int len = greeting.length();
```

Benefits over char*:
- Automatic memory management
- Rich API (length, substr, find, etc.)
- Safe concatenation and copying

### Memory Allocation

Dynamic memory in C++:

```cpp
// C-style
char* buffer = (char*)malloc(100);
free(buffer);

// C++ style
char* buffer = new char[100];
delete[] buffer;

// For single objects
int* num = new int(42);
delete num;
```

**Critical**: Every `new` needs a `delete`, every `malloc` needs a `free`.

### String Lifetime Management

Who owns the memory?

```cpp
// Returns pointer to local array - DANGEROUS!
const char* bad_function() {
    char buffer[20] = "Hello";
    return buffer;  // ⚠ buffer destroyed when function returns
}

// Correct: return allocated memory or std::string
const char* good_function() {
    return "Hello";  // String literal (in program memory)
}

std::string better_function() {
    return "Hello";  // Managed automatically
}
```

## Task 03: Arrays and Memory

### Pointers

Pointers store memory addresses:

```cpp
int value = 42;
int* ptr = &value;     // ptr points to value
int x = *ptr;          // x = 42 (dereference)
*ptr = 100;            // value is now 100
```

### Pointer Arithmetic

Pointers can be incremented/decremented:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int* ptr = arr;        // Points to arr[0]
ptr++;                 // Now points to arr[1]
int val = *ptr;        // val = 2
```

### Arrays in C++

Arrays are contiguous blocks of memory:

```cpp
int numbers[5];           // Uninitialized
int values[5] = {1,2,3,4,5};  // Initialized
int* ptr = values;        // Array name is pointer to first element
```

Array indexing is pointer arithmetic:
- `arr[i]` is equivalent to `*(arr + i)`

### WASM Linear Memory Model

WebAssembly has a single contiguous memory space:
- Module exports memory to JavaScript
- JavaScript can read/write WASM memory
- Use `Module.HEAP32`, `Module.HEAP8`, etc. from JS
- Memory addresses are integers

### JavaScript TypedArrays

JavaScript views into binary data:

```js
// Create view into WASM memory
const ptr = Module._malloc(20);
const view = new Int32Array(Module.HEAP32.buffer, ptr, 5);
view[0] = 42;  // Write to WASM memory
```

## Task 04: Classes and OOP

### Class Definition

Classes bundle data and functions:

```cpp
class Counter {
public:
    Counter(int initial);       // Constructor
    ~Counter();                 // Destructor
    void increment();           // Member function
    int get_value() const;      // Const member function

private:
    int value;                  // Member variable
};
```

### Constructors and Destructors

**Constructor** - called when object is created:

```cpp
Counter::Counter(int initial) : value(initial) {
    // Initialization code
}
```

**Destructor** - called when object is destroyed:

```cpp
Counter::~Counter() {
    // Cleanup code (free resources, etc.)
}
```

### Member Functions

Functions that operate on object data:

```cpp
void Counter::increment() {
    value++;  // Access member variable
}

int Counter::get_value() const {
    return value;  // const = doesn't modify object
}
```

### Access Modifiers

- `public:` - accessible from anywhere
- `private:` - only accessible within class
- `protected:` - accessible in class and subclasses

```cpp
class Counter {
public:
    void increment();  // Anyone can call
private:
    int value;        // Only Counter methods can access
};
```

### this Pointer

Every member function has implicit `this` pointer:

```cpp
void Counter::increment() {
    this->value++;  // Explicit
    value++;        // Implicit (same thing)
}
```

### Embind Library

Embind exposes C++ classes to JavaScript:

```cpp
#include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(counter_module) {
    emscripten::class_<Counter>("Counter")
        .constructor<int>()
        .function("increment", &Counter::increment)
        .function("getValue", &Counter::get_value);
}
```

From JavaScript:
```js
const counter = new Module.Counter(10);
counter.increment();
console.log(counter.getValue());  // 11
```

## Task 05: JSON Parser

### String Manipulation

Common std::string methods:

```cpp
std::string json = "{\"name\": \"value\"}";

size_t pos = json.find("name");        // Find substring
std::string sub = json.substr(5, 4);   // Extract substring
json.replace(0, 1, "[");              // Replace characters
```

### Parsing Algorithms

Common approaches:
- Character-by-character scanning
- State machines for tracking context
- Recursive descent for nested structures

Basic parsing pattern:

```cpp
std::string parse_value(const std::string& json, size_t& pos) {
    while (pos < json.length()) {
        char c = json[pos];
        if (c == '"') {
            // Parse string
        } else if (isdigit(c)) {
            // Parse number
        }
        pos++;
    }
}
```

### Error Handling

**Return codes**:
```cpp
int parse_json(const char* json, int* result) {
    if (!json) return -1;  // Error code
    // ... parse ...
    *result = value;
    return 0;  // Success
}
```

**Exceptions**:
```cpp
int parse_json(const char* json) {
    if (!json) throw std::invalid_argument("null json");
    // ... parse ...
    return value;
}
```

For WASM, return codes are often simpler than exceptions.

### Edge Case Handling

Always consider:
- Null/empty input
- Invalid format
- Missing keys
- Unterminated strings
- Buffer overflows
- Whitespace handling

## Common Debugging Tips

### Compiler Errors

Read from top to bottom - first error often causes others.

Common errors:
- `undefined reference` - missing function definition
- `no matching function` - wrong parameter types
- `expected ';'` - syntax error

### Segmentation Faults

Usually caused by:
- Dereferencing null pointer
- Accessing freed memory
- Array out of bounds
- Stack overflow (infinite recursion)

### Memory Leaks

Tools to detect:
- `valgrind` - memory leak detector
- Address sanitizer: `g++ -fsanitize=address`

Best practice: use RAII (Resource Acquisition Is Initialization) and smart pointers.

## Useful Resources

### Documentation
- [cppreference.com](https://en.cppreference.com/) - C++ reference
- [Emscripten docs](https://emscripten.org/docs/) - WASM compilation
- [MDN WebAssembly](https://developer.mozilla.org/en-US/docs/WebAssembly) - WASM in browsers

### Learning
- [LearnCpp.com](https://www.learncpp.com/) - comprehensive C++ tutorial
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) - best practices

## Progress Checklist

Track your learning:

- [ ] Task 01: Basic functions and WASM compilation
- [ ] Task 02: String handling and memory management
- [ ] Task 03: Pointers, arrays, and memory model
- [ ] Task 04: Classes, OOP, and Embind
- [ ] Task 05: Practical parsing application

Mark each task complete when all tests pass and you understand the concepts!
