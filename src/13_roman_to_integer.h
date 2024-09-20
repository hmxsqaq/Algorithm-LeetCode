#ifndef ALGORITHM_LEETCODE_13_ROMAN_TO_INTEGER_H
#define ALGORITHM_LEETCODE_13_ROMAN_TO_INTEGER_H

#include "utility.h"

class Solution13_RomanToInteger {
public:
    static int romanToIntBruteForce(std::string s) {
        int sum = 0;
        char previous_digit;
        for (auto digit : s) {
            if (digit == 'I') {
                sum += 1;
            } else if (digit == 'V') {
                sum += previous_digit == 'I' ? 3 : 5;
            } else if (digit == 'X') {
                sum += previous_digit == 'I' ? 8 : 10;
            } else if (digit == 'L') {
                sum += previous_digit == 'X' ? 30 : 50;
            } else if (digit == 'C') {
                sum += previous_digit == 'X' ? 80 : 100;
            } else if (digit == 'D') {
                sum += previous_digit == 'C' ? 300 : 500;
            } else if (digit == 'M') {
                sum += previous_digit == 'C' ? 800 : 1000;
            }
            previous_digit = digit;
        }
        return sum;
    }

    static int romanToInt(std::string s) {
        static std::unordered_map<char, int> roman_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 && roman_map[s[i]] < roman_map[s[i + 1]]) {
                sum -= roman_map[s[i]];
            } else {
                sum += roman_map[s[i]];
            }
        }
        return sum;
    }

    static void test() {
        std::string s = "MCMXCIV";
        LOG(romanToInt(s));
    }
};

#endif //ALGORITHM_LEETCODE_13_ROMAN_TO_INTEGER_H
