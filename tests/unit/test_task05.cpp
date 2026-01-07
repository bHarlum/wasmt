#include <cassert>
#include <iostream>
#include <cstring>

// Forward declarations
extern "C" int parse_json_int(const char* json, const char* key);
extern "C" const char* parse_json_string(const char* json, const char* key);
extern "C" bool is_valid_json(const char* json);

void test_parse_json_int_simple() {
    const char* json = "{\"age\": 25}";
    int result = parse_json_int(json, "age");
    assert(result == 25);
    std::cout << "✓ parse_json_int extracts integer value" << std::endl;
}

void test_parse_json_int_multiple_keys() {
    const char* json = "{\"age\": 30, \"score\": 95}";
    int age = parse_json_int(json, "age");
    int score = parse_json_int(json, "score");
    assert(age == 30);
    assert(score == 95);
    std::cout << "✓ parse_json_int handles multiple keys" << std::endl;
}

void test_parse_json_int_missing_key() {
    const char* json = "{\"age\": 25}";
    int result = parse_json_int(json, "missing");
    assert(result == -1);
    std::cout << "✓ parse_json_int returns -1 for missing key" << std::endl;
}

void test_parse_json_string_simple() {
    const char* json = "{\"name\": \"John\"}";
    const char* result = parse_json_string(json, "name");
    assert(result != nullptr);
    assert(strcmp(result, "John") == 0);
    std::cout << "✓ parse_json_string extracts string value" << std::endl;
}

void test_parse_json_string_multiple() {
    const char* json = "{\"name\": \"Alice\", \"city\": \"Portland\"}";
    const char* name = parse_json_string(json, "name");
    const char* city = parse_json_string(json, "city");
    assert(name != nullptr && strcmp(name, "Alice") == 0);
    assert(city != nullptr && strcmp(city, "Portland") == 0);
    std::cout << "✓ parse_json_string handles multiple string keys" << std::endl;
}

void test_parse_json_string_missing_key() {
    const char* json = "{\"name\": \"Bob\"}";
    const char* result = parse_json_string(json, "missing");
    assert(result == nullptr);
    std::cout << "✓ parse_json_string returns nullptr for missing key" << std::endl;
}

void test_is_valid_json_valid() {
    const char* json = "{\"name\": \"Test\", \"age\": 25}";
    assert(is_valid_json(json) == true);
    std::cout << "✓ is_valid_json recognizes valid JSON" << std::endl;
}

void test_is_valid_json_missing_brace() {
    const char* json = "{\"name\": \"Test\"";
    assert(is_valid_json(json) == false);
    std::cout << "✓ is_valid_json detects missing closing brace" << std::endl;
}

void test_is_valid_json_empty() {
    const char* json = "{}";
    assert(is_valid_json(json) == true);
    std::cout << "✓ is_valid_json accepts empty object" << std::endl;
}

void test_is_valid_json_invalid() {
    const char* json = "not json";
    assert(is_valid_json(json) == false);
    std::cout << "✓ is_valid_json rejects invalid JSON" << std::endl;
}

void test_parse_mixed_types() {
    const char* json = "{\"name\": \"Alice\", \"age\": 30, \"city\": \"NYC\"}";
    const char* name = parse_json_string(json, "name");
    int age = parse_json_int(json, "age");
    const char* city = parse_json_string(json, "city");

    assert(strcmp(name, "Alice") == 0);
    assert(age == 30);
    assert(strcmp(city, "NYC") == 0);
    std::cout << "✓ Can parse mixed string and int types" << std::endl;
}

int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Running Task 05 Unit Tests..." << std::endl;
    std::cout << "========================================\n" << std::endl;

    try {
        test_parse_json_int_simple();
        test_parse_json_int_multiple_keys();
        test_parse_json_int_missing_key();
        test_parse_json_string_simple();
        test_parse_json_string_multiple();
        test_parse_json_string_missing_key();
        test_is_valid_json_valid();
        test_is_valid_json_missing_brace();
        test_is_valid_json_empty();
        test_is_valid_json_invalid();
        test_parse_mixed_types();

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
