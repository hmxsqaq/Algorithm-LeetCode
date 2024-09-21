# 14. Longest Common Prefix

> https://leetcode.com/problems/longest-common-prefix/
> 
> [Solution](../src/14_longest_common_prefix.h)

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

## Horizontal Scanning

We can first assume that the first string is the longest common prefix. Then we compare the prefix with each string and update the prefix accordingly.

```cpp
std::string LongestCommonPrefix_Horizontal(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    std::string& prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        int j = 0;
        for (; j < prefix.size(); ++j) {
            if (j >= strs[i].size() || prefix[j] != strs[i][j]) break;
        }
        prefix = strs[i].substr(0, j);
    }
    return prefix;
}
```

- Time complexity: $O(MN)$, where $M$ is the length of the longest common prefix and $N$ is the number of strings.
- Space complexity: $O(1)$

## Vertical Scanning

It is pretty much the same as the horizontal scanning, but we scan vertically instead of horizontally, which means we compare the characters at the same index of each string.

```cpp
std::string LongestCommonPrefix_Vertical(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    for (int j = 0; j < strs[0].size(); ++j) {
        char c = strs[0][j];
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i][j] != c || j >= strs[i].size())
                return strs[0].substr(0, j);
        }
    }
    return strs[0];
}
```

- Time complexity: $O(MN)$
- Space complexity: $O(1)$

## Divide and Conquer

This idea is similar to the merge sort algorithm. We divide the array of strings recursively until we have only one string. Then we merge the strings by finding the longest common prefix of the two strings.

```cpp
std::string GetCommonPrefix(const std::string& left, const std::string& right) {
    size_t min_length = std::min(left.size(), right.size());
    int i = 0;
    for (; i < min_length; ++i)
        if (left[i] != right[i]) break;
    return left.substr(0, i);
}

std::string LongestCommonPrefix_DivideAndConquer(std::vector<std::string>& strs, size_t left, size_t right) {
    if (left == right) return strs[left];
    size_t mid = (left + right) / 2;
    std::string left_str = LongestCommonPrefix_DivideAndConquer(strs, left, mid);
    std::string right_str = LongestCommonPrefix_DivideAndConquer(strs, mid + 1, right);
    return GetCommonPrefix(left_str, right_str);
}

std::string LongestCommonPrefix_DivideAndConquer(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    return LongestCommonPrefix_DivideAndConquer(strs, 0, strs.size() - 1);
}
```

- Time complexity: $O(MN)$
- Space complexity: $O(logN)$

## Binary Search

We can find the shortest string in the array and use binary search to find the longest common prefix. We compare the prefix with the middle string and update the search range accordingly.

```cpp
bool IsCommonPrefix(std::vector<std::string>& strs, size_t length) {
    std::string prefix = strs[0].substr(0, length);
    for (int i = 1; i < strs.size(); ++i)
        if (strs[i].find(prefix) != 0) return false;
    return true;
}

std::string LongestCommonPrefix_BinarySearch(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    size_t min_length = strs[0].size();
    for (int i = 1; i < strs.size(); ++i)
        min_length = std::min(min_length, strs[i].size());
    size_t low = 0, high = min_length;
    while (low < high) {
        size_t mid = (high + low + 1) / 2;
        if (IsCommonPrefix(strs, mid))
            low = mid;
        else
            high = mid - 1;
    }
    return strs[0].substr(0, low);
}
```

- Time complexity: $O(MNlogM)$
- Space complexity: $O(1)$

## Trie

We can build a trie from the array of strings and find the longest common prefix by traversing the trie.

If we need to find the longest common prefix multiple times, building a trie is more efficient than other methods.

```cpp
struct TrieNode {
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
    bool is_end = false;
};

class Trie {
    public:
    std::shared_ptr<TrieNode> root;
    Trie() { root = std::make_shared<TrieNode>(); }

    void Insert(const std::string &word) const {
        auto node = root;
        for (const char& c : word) {
            if (!node->children.contains(c))
                node->children[c] = std::make_shared<TrieNode>();
            node = node->children[c];
        }
        node->is_end = true;
    }

    [[nodiscard]] std::string GetLongestCommonPrefix() const {
        std::string prefix;
        auto node = root;
        while (node != nullptr && node->children.size() == 1 && !node->is_end) {
            const auto &it = node->children.begin();
            prefix.push_back(it->first);
            node = it->second;
        }
        return prefix;
    }
};

std::string LongestCommonPrefix_Trie(std::vector<std::string>& strs) {
    if (strs.empty()) return "";
    Trie trie;
    for (const auto& str : strs)
        trie.Insert(str);
    return trie.GetLongestCommonPrefix();
}
```

- Time complexity: $O(MN)$
- Space complexity: $O(MN)$