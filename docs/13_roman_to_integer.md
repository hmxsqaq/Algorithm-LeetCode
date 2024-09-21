# 13. Roman To Integer

> https://leetcode.com/problems/roman-to-integer/
>
> [Solution](../src/13_roman_to_integer.h)

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

| Symbol | Value |
|:------:|:-----:|
|   I    |   1   |
|   V    |   5   |
|   X    |  10   |
|   L    |  50   |
|   C    |  100  |
|   D    |  500  |
|   M    | 1000  |

For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9.
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90.
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

## Brute Force

Loop through the string `s` from left to right, and add the corresponding value of each character to the result.

To handle situations like `IV`, we can store the value of the previous character, and if the previous value is special, we will change the value of the current character to `value - 2 * previous_value`.

```cpp
int RomanToIntBruteForce(std::string s) {
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
```

- Time complexity: $O(N)$
- Space complexity: $O(1)$

## Map

In previous solution, we have to artificially handle the special cases. We can use a map to store the value of each character, and then we can simply add the value of each character to the result.

```cpp
int RomanToInt(std::string s) {
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
```

- Time complexity: $O(N)$
- Space complexity: $O(1)$