// main entry point for the program. Ideally in the future we'll setup a testing
// framework like Gtest, but this will be okay for now just for quick testing.

#include <iostream>
#include "libtokenizer/libtokenizer.hpp"

int main() {
    pytokenizer::core::Tokenizer tokenizer;
    std::cout << tokenizer.foo() << std::endl;
    return 0;
}