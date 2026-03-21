#pragma once

#include <vector>
#include <map>
#include <utility>
#include <string>

namespace pytokenizer {
namespace core {

class Tokenizer {
public:
    static std::map<std::pair<int, int>, int> get_stats(const std::vector<int>& ids);
    static std::vector<int> merge(const std::vector<int>& ids, const std::pair<int, int>& pair, int idx);
    std::string foo();
};

} // namespace core
} // namespace pytokenizer