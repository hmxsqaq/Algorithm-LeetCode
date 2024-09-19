#ifndef ALGORITHM_LEETCODE_9_PALINDROME_NUMBER_H
#define ALGORITHM_LEETCODE_9_PALINDROME_NUMBER_H

#include "utility.h"

class Solution9_PalindromeNumber {
public:
    static bool isPalindrome_ToString(int x) {
        if (x < 0) return false;
        std::string x_string = std::to_string(x);
        size_t i = 0, j = x_string.size() - 1;
        while (i < j) {
            if (x_string[i] != x_string[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    static bool isPalindrome_Reverse(int x) {
        if (x < 0) return false;
        size_t temp = x, x_reversed = 0;
        while (temp != 0){
            size_t digit = temp % 10;
            temp = temp / 10;
            x_reversed = x_reversed * 10 + digit;
        }
        return (x_reversed == x);
    }

    static bool isPalindrome_ReverseHalf(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        size_t x_reversed = 0;
        while (x > x_reversed) {
            x_reversed = x_reversed * 10 + x % 10;
            x /= 10;
        }
        return (x == x_reversed) || (x == x_reversed / 10);
    }

    static void test(){
        const int x = 121;
        LOG(Solution9_PalindromeNumber::isPalindrome_Reverse(x));
    }
};

#endif //ALGORITHM_LEETCODE_9_PALINDROME_NUMBER_H
