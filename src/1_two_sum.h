#ifndef ALGORITHM_LEETCODE_1_TWO_SUM_H
#define ALGORITHM_LEETCODE_1_TWO_SUM_H

#include "utility.h"

class Solution1_TwoSum {
public:
    static std::vector<int> TwoSum_BruteForce(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {0};
    }

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

    static std::vector<int> TwoSum_OnePassHashTable(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) != hash.end())
                return {i, hash[nums[i]]};
            hash[target - nums[i]] = i;
        }
        return {0};
    }

    static void Test(){
        std::vector<int> nums = {3, 2, 4};
        int target = 6;
        LOG(Solution1_TwoSum::TwoSum_OnePassHashTable(nums, target));
    }
};

#endif //ALGORITHM_LEETCODE_1_TWO_SUM_H
