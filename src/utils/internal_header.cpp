#include "utils/internal_header.h"

#include <random>

static std::string generate_random_header() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 35);
    const char* chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result = "X-";
    for (int i = 0; i < 16; i++) {
        result += chars[dis(gen)];
    }
    return result;
}

const std::string internal_request_header = generate_random_header();
