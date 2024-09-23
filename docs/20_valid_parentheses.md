# 20. Valid Parentheses

> https://leetcode.com/problems/valid-parentheses/
>
> [Solution](../src/20_valid_parentheses.h)

Given a string s containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## Stack & Hash Map

We can use a stack to store the open brackets and a hash map to store the mappings of the brackets. 

When we encounter an open bracket, we push it into the stack. When we encounter a close bracket, we check if the stack is empty or the top of the stack is not the corresponding open bracket. If so, we return `false`. Otherwise, we pop the top of the stack.

```cpp
bool IsValid(const std::string& s) {
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
```

- Time complexity: $O(N)$
- Space complexity: $O(N)$