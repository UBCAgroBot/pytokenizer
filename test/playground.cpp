// main entry point for the program. Ideally in the future we'll setup a testing
// framework like Gtest, but this will be okay for now just for quick testing.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "libtokenizer/libtokenizer.hpp"

int main() {
    using namespace pytokenizer::core;

    std::string text = "Wow, C++ is so hard!";
    std::vector<int> ids(text.begin(), text.end());

    int next_id = 256;
    for (int i = 0; i < 3; ++i) {
        auto stats = Tokenizer::get_stats(ids);
        auto best = std::max_element(stats.begin(), stats.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });

        std::cout << "Merging (" << best->first.first << ", " << best->first.second
                  << ") -> " << next_id << "  [freq=" << best->second << "]\n";

        ids = Tokenizer::merge(ids, best->first, next_id++);
    }

    std::cout << "Final ids:";
    for (int id : ids) std::cout << " " << id;
    std::cout << "\n";

    return 0;
}