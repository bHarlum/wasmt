#include <cassert>
#include <iostream>
#include <cstring>

// Forward declarations
extern "C" const char* greet(const char* name);
extern "C" int get_greeting_length(const char* name);

void test_greet_world() {
    const char* result = greet("World");
    assert(strcmp(result, "Hello, World!") == 0);
    std::cout << "✓ greet(\"World\") == \"Hello, World!\"" << std::endl;
}

void test_greet_custom_name() {
    const char* result = greet("Bryce");
    assert(strcmp(result, "Hello, Bryce!") == 0);
    std::cout << "✓ greet(\"Bryce\") == \"Hello, Bryce!\"" << std::endl;
}

void test_greet_empty() {
    const char* result = greet("");
    assert(strcmp(result, "Hello, !") == 0);
    std::cout << "✓ greet(\"\") == \"Hello, !\"" << std::endl;
}

void test_greeting_length() {
    int length = get_greeting_length("Test");
    assert(length == 12);  // "Hello, Test!" is 12 characters
    std::cout << "✓ get_greeting_length(\"Test\") == 12" << std::endl;
}

void test_greeting_length_long_name() {
    int length = get_greeting_length("Alexander");
    assert(length == 17);  // "Hello, Alexander!" is 17 characters
    std::cout << "✓ get_greeting_length(\"Alexander\") == 17" << std::endl;
}

void test_greeting_length_empty() {
    int length = get_greeting_length("");
    assert(length == 8);  // "Hello, !" is 8 characters
    std::cout << "✓ get_greeting_length(\"\") == 8" << std::endl;
}

int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Running Task 02 Unit Tests..." << std::endl;
    std::cout << "========================================\n" << std::endl;

    try {
        test_greet_world();
        test_greet_custom_name();
        test_greet_empty();
        test_greeting_length();
        test_greeting_length_long_name();
        test_greeting_length_empty();

        std::cout << "\n========================================" << std::endl;
        std::cout << "✓ All tests PASSED!" << std::endl;
        std::cout << "========================================\n" << std::endl;
        return 0;
    } catch (...) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "✗ Tests FAILED!" << std::endl;
        std::cout << "========================================\n" << std::endl;
        return 1;
    }
}
