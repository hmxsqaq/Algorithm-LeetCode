#ifndef ALGORITHM_LEETCODE_20_VALID_PARENTHESES_H
#define ALGORITHM_LEETCODE_20_VALID_PARENTHESES_H

#include "utility.h"

class Solution20_ValidParentheses {
public:
    static bool IsValid(const std::string& s) {
        if (s.size() <= 1) return false;
        static std::unordered_map<char, char> compare_table {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            else if (c == ')' || c == ']' || c == '}') {
                if (stack.empty() || stack.top() != compare_table[c]) return false;
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }

    static void Test() {
        std::string s = "){";
        LOG(IsValid(s));
    }
};

#endif //ALGORITHM_LEETCODE_20_VALID_PARENTHESES_H
