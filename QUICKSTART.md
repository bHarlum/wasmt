# Quick Start Guide

Get started with Task 01 in 5 minutes!

## Prerequisites

Make sure you've completed [SETUP.md](SETUP.md) and have all tools installed.

## Step 1: Read the Task Specification

```bash
cat tasks/TASK_01.md
```

This tells you:
- What you need to implement
- What tests expect
- Which C++ concepts you'll learn

## Step 2: Try to Build (It Will Fail)

```bash
make build-unit-task01
```

You'll see an error like:
```
g++: error: src/math_ops.cpp: No such file or directory
```

This is expected! You haven't created the implementation yet.

## Step 3: Create Your Implementation

Create the file:
```bash
vim src/math_ops.cpp
# or use your preferred editor
```

Implement the `add()` function according to the task spec. The unit tests in `tests/unit/test_task01.cpp` show what's expected.

Hints:
- You need `extern "C"` linkage
- You need `EMSCRIPTEN_KEEPALIVE` macro
- Check [LEARNING.md](LEARNING.md) for Task 01 concepts

## Step 4: Build and Run Unit Tests

```bash
make build-unit-task01
make test-unit-task01
```

If tests fail, iterate:
```bash
vim src/math_ops.cpp
make test-unit-task01
```

Keep going until you see:
```
All tests PASSED!
```

## Step 5: Compile to WebAssembly

```bash
make build-wasm-task01
```

This creates:
- `build/wasm/math_ops.wasm` - the WebAssembly binary
- `build/wasm/math_ops.js` - JavaScript glue code

## Step 6: Run Integration Tests

Start the web server:
```bash
make serve
```

Open in your browser:
```
http://localhost:8000/tests/integration/test_task01.html
```

You should see green checkmarks if everything works!

## Step 7: Move to Task 02

```bash
cat tasks/TASK_02.md
```

Repeat the process with Task 02.

## Common Workflow Commands

```bash
# Build and test (unit)
make build-unit-taskXX
make test-unit-taskXX

# Build WASM
make build-wasm-taskXX

# Start web server for integration tests
make serve

# Clean build artifacts
make clean

# See all available targets
make help
```

## Tips

- Read the task specification thoroughly before starting
- Look at the test code to understand expected behavior
- Use [LEARNING.md](LEARNING.md) as a reference for C++ concepts
- Unit tests give fast feedback - use them to iterate quickly
- Integration tests validate the final WASM output

## Stuck?

- Check [LEARNING.md](LEARNING.md) for C++ concepts
- Read the test code to see what's expected
- Look at compiler error messages carefully
- Research C++ documentation online

## Success Indicators

You've completed a task when:
- Unit tests all pass
- Integration tests all pass
- No compiler warnings
- You understand the concepts used

Now start with Task 01! Read `tasks/TASK_01.md` and begin implementing.
