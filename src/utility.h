#ifndef ALGORITHM_LEETCODE_UTILITY_H
#define ALGORITHM_LEETCODE_UTILITY_H

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <memory>

#define LOG(message) std::cout << message << "\n"

std::ostream& operator<<(std::ostream &out, const std::vector<int> &nums) {
    out << "[";
    for (int i = 0; i < nums.size() - 1; ++i) {
        out << nums[i] << ", ";
    }
    out << nums[nums.size() - 1] << "]";
    return out;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    [[nodiscard]] std::string ToString() const {
        std::string result = std::to_string(val);
        ListNode* current = next;
        while (current != nullptr) {
            result += " -> " + std::to_string(current->val);
            current = current->next;
        }
        return result;
    }
};

#endif //ALGORITHM_LEETCODE_UTILITY_H
