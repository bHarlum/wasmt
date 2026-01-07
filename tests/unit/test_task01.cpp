#include <cassert>
#include <iostream>

// Forward declaration of function to test
extern "C" int add(int a, int b);

void test_add_positive_numbers() {
    assert(add(2, 3) == 5);
    std::cout << "✓ add(2, 3) == 5" << std::endl;
}

void test_add_with_negative() {
    assert(add(-1, 1) == 0);
    std::cout << "✓ add(-1, 1) == 0" << std::endl;
}

void test_add_large_numbers() {
    assert(add(100, 200) == 300);
    std::cout << "✓ add(100, 200) == 300" << std::endl;
}

void test_add_negative_result() {
    assert(add(-5, -3) == -8);
    std::cout << "✓ add(-5, -3) == -8" << std::endl;
}

int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Running Task 01 Unit Tests..." << std::endl;
    std::cout << "========================================\n" << std::endl;

    try {
        test_add_positive_numbers();
        test_add_with_negative();
        test_add_large_numbers();
        test_add_negative_result();

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
