# C++ to WebAssembly Learning Project

A test-driven learning project for mastering C++ fundamentals while building a real WebAssembly library.

## What is This?

This project teaches C++ through **red/green testing**:
- All tests start **FAILING** (red)
- You implement code to make them **PASSING** (green)
- Clear, binary feedback on your progress

## Target Learner

- Experienced engineer with TypeScript/JavaScript/Go background
- No prior C++ experience required
- Comfortable with Linux, command line, and build tools
- Prefers learning by doing with clear objectives

## Project Structure

```
wasmt/
├── src/                    # Your C++ implementations go here
├── tests/
│   ├── unit/              # C++ unit tests (fast feedback)
│   └── integration/       # Browser WASM tests (real-world validation)
├── tasks/                 # Task specifications and requirements
└── build/                 # Compiled artifacts (gitignored)
```

## Two-Layer Testing

### Unit Tests (C++ Native)
- Fast feedback on C++ logic
- Run with `make test-unit-taskXX`
- No WASM compilation needed

### Integration Tests (Browser + WASM)
- Validate WASM compilation and JS interop
- Compile with `make build-wasm-taskXX`
- Open in browser after running `make serve`

## Quick Start

See [QUICKSTART.md](QUICKSTART.md) for a step-by-step guide to Task 01.

## Task Progression

1. **Task 01: Basic Functions** - Hello WASM with simple arithmetic
2. **Task 02: Strings** - String handling and memory management
3. **Task 03: Arrays and Memory** - Pointers, arrays, and WASM memory model
4. **Task 04: Classes and OOP** - Object-oriented programming with Embind
5. **Task 05: JSON Parser** - Practical application with parsing and algorithms

Each task includes:
- Task specification in `tasks/TASK_XX.md`
- Failing unit tests in `tests/unit/`
- Failing integration tests in `tests/integration/`
- Learning resources in [LEARNING.md](LEARNING.md)

## Documentation

- [SETUP.md](SETUP.md) - Installation and prerequisites
- [QUICKSTART.md](QUICKSTART.md) - Get started in 5 minutes
- [LEARNING.md](LEARNING.md) - C++ concepts, resources, and tips

## Typical Workflow

```bash
# Read the task specification
cat tasks/TASK_01.md

# Create your implementation
vim src/math_ops.cpp

# Build and run unit tests
make build-unit-task01
make test-unit-task01

# Iterate until tests pass
vim src/math_ops.cpp
make test-unit-task01

# Compile to WASM
make build-wasm-task01

# Test in browser
make serve
# Open http://localhost:8000/tests/integration/test_task01.html
```

## Success Criteria

A task is complete when:
- All unit tests pass
- All integration tests pass
- Code compiles without warnings
- You understand the concepts used

## Getting Help

- Check [LEARNING.md](LEARNING.md) for C++ concepts
- Read task specifications in `tasks/` for requirements
- Review test code to understand expected behavior
- Research C++ documentation online

Start with [SETUP.md](SETUP.md) to install prerequisites, then [QUICKSTART.md](QUICKSTART.md) to begin Task 01!
