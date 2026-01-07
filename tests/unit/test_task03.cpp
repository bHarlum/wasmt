#include <cassert>
#include <iostream>

// Forward declarations
extern "C" int sum_array(int* arr, int length);
extern "C" void multiply_array(int* arr, int length, int multiplier);
extern "C" int* create_sequence(int length);

void test_sum_array_simple() {
    int arr[] = {1, 2, 3, 4, 5};
    int result = sum_array(arr, 5);
    assert(result == 15);
    std::cout << "✓ sum_array([1,2,3,4,5], 5) == 15" << std::endl;
}

void test_sum_array_larger() {
    int arr[] = {10, 20, 30};
    int result = sum_array(arr, 3);
    assert(result == 60);
    std::cout << "✓ sum_array([10,20,30], 3) == 60" << std::endl;
}

void test_sum_array_single() {
    int arr[] = {42};
    int result = sum_array(arr, 1);
    assert(result == 42);
    std::cout << "✓ sum_array([42], 1) == 42" << std::endl;
}

void test_multiply_array_by_two() {
    int arr[] = {1, 2, 3};
    multiply_array(arr, 3, 2);
    assert(arr[0] == 2 && arr[1] == 4 && arr[2] == 6);
    std::cout << "✓ multiply_array([1,2,3], 3, 2) modifies to [2,4,6]" << std::endl;
}

void test_multiply_array_by_zero() {
    int arr[] = {5, 10, 15};
    multiply_array(arr, 3, 0);
    assert(arr[0] == 0 && arr[1] == 0 && arr[2] == 0);
    std::cout << "✓ multiply_array([5,10,15], 3, 0) modifies to [0,0,0]" << std::endl;
}

void test_multiply_array_by_negative() {
    int arr[] = {1, 2, 3};
    multiply_array(arr, 3, -1);
    assert(arr[0] == -1 && arr[1] == -2 && arr[2] == -3);
    std::cout << "✓ multiply_array([1,2,3], 3, -1) modifies to [-1,-2,-3]" << std::endl;
}

void test_create_sequence() {
    int* seq = create_sequence(5);
    assert(seq != nullptr);
    assert(seq[0] == 0);
    assert(seq[1] == 1);
    assert(seq[2] == 2);
    assert(seq[3] == 3);
    assert(seq[4] == 4);
    std::cout << "✓ create_sequence(5) creates [0,1,2,3,4]" << std::endl;
    delete[] seq;  // Clean up
}

void test_create_sequence_single() {
    int* seq = create_sequence(1);
    assert(seq != nullptr);
    assert(seq[0] == 0);
    std::cout << "✓ create_sequence(1) creates [0]" << std::endl;
    delete[] seq;  // Clean up
}

int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Running Task 03 Unit Tests..." << std::endl;
    std::cout << "========================================\n" << std::endl;

    try {
        test_sum_array_simple();
        test_sum_array_larger();
        test_sum_array_single();
        test_multiply_array_by_two();
        test_multiply_array_by_zero();
        test_multiply_array_by_negative();
        test_create_sequence();
        test_create_sequence_single();

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
