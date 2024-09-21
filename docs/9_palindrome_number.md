# 9. Palindrome Number

> https://leetcode.com/problems/palindrome-number/
> 
> [Solution](../src/9_palindrome_number.h)

Given an integer `x`, return _`true` if `x` is a [palindrome](https://en.wikipedia.org/wiki/Palindrome), and `false` otherwise._

## To String

Simply convert the `x` to a `std::string`, then we can access each digit by index.

```c++
bool IsPalindrome_ToString(int x) {
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
```

- Time complexity: $O(N)$
- Space complexity: $O(N)$

## Reverse

We can reverse `x` and compare it with the original number.

```c++
bool IsPalindrome_Reverse(int x) {
    if (x < 0) return false;
    size_t temp = x, x_reversed = 0;
    while (temp != 0){
        size_t digit = temp % 10;
        temp = temp / 10;
        x_reversed = x_reversed * 10 + digit;
    }
    return (x_reversed == x);
}
```

- Time complexity: $O(logN)$
- Space complexity: $O(1)$

## Reverse Half

Actually we can just reverse half of the number and compare it with the other half.

```c++
bool IsPalindrome_ReverseHalf(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    size_t x_reversed = 0;
    while (x > x_reversed) {
        x_reversed = x_reversed * 10 + x % 10;
        x /= 10;
    }
    return (x == x_reversed) || (x == x_reversed / 10);
}
```

- Time complexity: $O(logN/2)$
- Space complexity: $O(1)$