//
// Created by isaac on 1/25/2024.
//

#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        auto end = remove(nums.begin(), nums.end(), val);
        return static_cast<int>(distance(nums.begin(), end));
    }
};

#include <gtest/gtest.h>

TEST(RemoveElementTest, Test1) {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    Solution solution;
    int k = solution.removeElement(nums, val);

    std::vector<int> expectedNums = {2, 2};
    std::sort(nums.begin(), nums.begin() + k);
    std::sort(expectedNums.begin(), expectedNums.end());

    ASSERT_EQ(k, expectedNums.size());
    for (int i = 0; i < k; ++i) {
        ASSERT_EQ(nums[i], expectedNums[i]) << "Index i: " << i;;
    }
}

TEST(RemoveElementTest, Test2) {
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution solution;
    int k = solution.removeElement(nums, val);

    std::vector<int> expectedNums = {0, 1, 4, 0, 3};
    std::sort(nums.begin(), nums.begin() + k);
    std::sort(expectedNums.begin(), expectedNums.end());

    ASSERT_EQ(k, expectedNums.size());
    for (int i = 0; i < k; ++i) {
        ASSERT_EQ(nums[i], expectedNums[i]) << "Index i: " << i;;
    }
}
