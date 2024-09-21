# 1. Two Sum

> https://leetcode.com/problems/two-sum/
> 
> [Solution](../src/1_two_sum.h)

Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`._

You may assume that each input would have **_exactly one solution_**, and you may not use the same element twice.

You can return the answer in any order.

## Brute Force

Loop through each element $x$ and find if there is another value that equals to $target - x$

```c++
std::vector<int> TwoSum_BruteForce(std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) return {i, j};
        }
    }
    return {0};
}
```

- Time complexity: $O(N^2)$
- Space complexity: $O(1)$

## Hash Table

Loop through the array and use a hash table to store the index of $target - x$ for each element $x$.

Then loop through the array again and find if there is a value in the hash table that equals to the current element, which means we found the answer.

Because the `find` operation of a hash table is $O(1)$, the time complexity can be significantly reduced.

```c++
static std::vector<int> TwoSum_TwoPassHashTable(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i)
        hash[target - nums[i]] = i;

    for (int i = 0; i < nums.size(); ++i) {
        if (hash.find(nums[i]) != hash.end() && i != hash[nums[i]])
            return {i, hash[nums[i]]};
    }
    return {0};
}
```

- Time complexity: $O(N)$
- Space complexity: $O(N)$

Actually, we can combine the two loops into one loop, and return the answer immediately when we find it.

```c++
static std::vector<int> TwoSum_OnePassHashTable(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
        if (hash.find(nums[i]) != hash.end())
            return {i, hash[nums[i]]};
        hash[target - nums[i]] = i;
    }
    return {0};
}
```