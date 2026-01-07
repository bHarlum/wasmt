#include <cassert>
#include <iostream>
#include "../../../src/counter.h"

void test_counter_initialization() {
    Counter counter(10);
    assert(counter.get_value() == 10);
    std::cout << "✓ Counter initializes with correct value" << std::endl;
}

void test_counter_increment() {
    Counter counter(5);
    counter.increment();
    assert(counter.get_value() == 6);
    counter.increment();
    assert(counter.get_value() == 7);
    std::cout << "✓ Counter increment() works correctly" << std::endl;
}

void test_counter_decrement() {
    Counter counter(10);
    counter.decrement();
    assert(counter.get_value() == 9);
    counter.decrement();
    assert(counter.get_value() == 8);
    std::cout << "✓ Counter decrement() works correctly" << std::endl;
}

void test_counter_reset() {
    Counter counter(42);
    counter.increment();
    counter.increment();
    counter.reset();
    assert(counter.get_value() == 0);
    std::cout << "✓ Counter reset() sets value to 0" << std::endl;
}

void test_counter_negative_values() {
    Counter counter(0);
    counter.decrement();
    counter.decrement();
    assert(counter.get_value() == -2);
    std::cout << "✓ Counter handles negative values correctly" << std::endl;
}

void test_multiple_instances() {
    Counter counter1(10);
    Counter counter2(20);

    counter1.increment();
    counter2.decrement();

    assert(counter1.get_value() == 11);
    assert(counter2.get_value() == 19);
    std::cout << "✓ Multiple Counter instances maintain separate state" << std::endl;
}

void test_counter_chain_operations() {
    Counter counter(0);
    counter.increment();
    counter.increment();
    counter.increment();
    counter.decrement();
    assert(counter.get_value() == 2);
    std::cout << "✓ Counter handles chained operations correctly" << std::endl;
}

int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Running Task 04 Unit Tests..." << std::endl;
    std::cout << "========================================\n" << std::endl;

    try {
        test_counter_initialization();
        test_counter_increment();
        test_counter_decrement();
        test_counter_reset();
        test_counter_negative_values();
        test_multiple_instances();
        test_counter_chain_operations();

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
