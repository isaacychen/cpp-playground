//
// Created by isaac on 1/29/2024.
//

#include <format>
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

namespace p0045 {
    class Solution {
    public:
        int canJump(vector<int>& nums) {
            int maxReachableIndex = 0, lastStepMaxReachableIndex = 0, steps = 0;
            for (int i = 0; i < nums.size() && maxReachableIndex < nums.size() - 1; ++i) {
                if (maxReachableIndex < i)
                    return -1;
                maxReachableIndex = max(i + nums[i], maxReachableIndex);
                if (lastStepMaxReachableIndex == i || maxReachableIndex >= nums.size() - 1) {
                    ++steps;
                    lastStepMaxReachableIndex = maxReachableIndex;
                }
            }
            return steps;
        }
    };

    class P0045JumpGame2Test : public testing::TestWithParam<std::tuple<std::vector<int>, int>> {
    };

    TEST_P(P0045JumpGame2Test, Testcases) {
        std::vector<int> input = std::get<0>(GetParam());
        const bool expectedResult = std::get<1>(GetParam());

        Solution solution;
        const bool result = solution.canJump(input);

        ASSERT_EQ(result, expectedResult);
    }

    INSTANTIATE_TEST_SUITE_P(LeedCode, P0045JumpGame2Test,
                             testing::Values(
                                 std::make_tuple(std::vector<int>{2,3,1,1,4}, 2),
                                 std::make_tuple(std::vector<int>{2,3,0,1,4}, 2)
                             )
    );
}
