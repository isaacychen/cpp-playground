//
// Created by isaac on 1/26/2024.
//

#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
//        size_t j = 1;
//        for (size_t i = 1; i < nums.size(); i++) {
//            if (nums[i] != nums[i - 1]) {
//                nums[j] = nums[i];
//                j++;
//            }
//        }
//        return static_cast<int>(j);
        auto end = nums.end();
        for (auto begin = nums.begin() + 1; begin < end; begin++) {
            end = remove_if(begin, end, [begin](int x) { return x == *(begin - 1); });
        }
        return static_cast<int>(distance(nums.begin(), end));
    }
};

#include "gtest/gtest.h"

class RemoveDuplicatesTest : public testing::TestWithParam<std::vector<int>> {
protected:
    Solution solution;
};

TEST_P(RemoveDuplicatesTest, CheckRemoveDuplicates) {
    std::vector<int> nums = GetParam();
    int k = solution.removeDuplicates(nums);

    std::vector<int> expectedNums = GetParam();
    expectedNums.erase(std::unique(expectedNums.begin(), expectedNums.end()), expectedNums.end());

    ASSERT_EQ(k, expectedNums.size());

    for (int i = 0; i < k; ++i) {
        ASSERT_EQ(nums[i], expectedNums[i]);
    }
}

INSTANTIATE_TEST_SUITE_P(Tests,
                         RemoveDuplicatesTest,
                         ::testing::Values(
                                 std::vector<int>{1, 1, 2},
                                 std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
                         )
);