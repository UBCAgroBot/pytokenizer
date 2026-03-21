#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "libtokenizer/libtokenizer.hpp"

namespace pytokenizer {
namespace core {

std::map<std::pair<int, int>, int> Tokenizer::get_stats(const std::vector<int>& ids) {
    std::map<std::pair<int, int>, int> counts;
    for (size_t i = 0; i < ids.size() - 1; ++i) {
        std::pair<int, int> pair = {ids[i], ids[i + 1]};
        counts[pair]++;
    }
    return counts;
}

std::vector<int> Tokenizer::merge(const std::vector<int>& ids, const std::pair<int, int>& pair, int idx) {
    std::vector<int> newids;
    size_t i = 0;
    while (i < ids.size()) {
        if (i < ids.size() - 1 && ids[i] == pair.first && ids[i + 1] == pair.second) {
            newids.push_back(idx);
            i += 2;
        } else {
            newids.push_back(ids[i]);
            i += 1;
        }
    }
    return newids;
}

} // namespace core
} // namespace pytokenizer