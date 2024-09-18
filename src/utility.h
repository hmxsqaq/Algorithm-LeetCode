#ifndef ALGORITHM_LEETCODE_UTILITY_H
#define ALGORITHM_LEETCODE_UTILITY_H

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#define LOG(message) std::cout << message << "\n"

std::ostream& operator<<(std::ostream &out, const std::vector<int> &nums) {
    out << "[";
    for (int i = 0; i < nums.size() - 1; ++i) {
        out << nums[i] << ", ";
    }
    out << nums[nums.size() - 1] << "]";
    return out;
}

#endif //ALGORITHM_LEETCODE_UTILITY_H
