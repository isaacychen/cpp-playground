//
// Created by isaac on 1/27/2024.
//

#include <vector>
#include <algorithm>

using namespace std;

namespace p0169 {
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            ranges::sort(nums);
            return nums[nums.size() / 2];
        }
    };
}

#include <gtest/gtest.h>

TEST(P0169MajorityElement, Test1) {
    vector nums{3, 2, 3};

    p0169::Solution solution;
    const int result = solution.majorityElement(nums);

    constexpr int expectedResult{3};
    ASSERT_EQ(result, expectedResult);
}

TEST(P0169MajorityElement, Test2) {
    vector nums{2, 2, 1, 1, 1, 2, 2};

    p0169::Solution solution;
    const int result = solution.majorityElement(nums);

    constexpr int expectedResult{2};
    ASSERT_EQ(result, expectedResult);
}
