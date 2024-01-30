//
// Created by isaac on 1/29/2024.
//

#include <format>
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

namespace p0055 {
    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxReachableIndex = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (maxReachableIndex < i) return false;
                maxReachableIndex = max(i + nums[i], maxReachableIndex);
            }
            return true;
        }
    };

    class P0055JumpGameTest : public testing::TestWithParam<std::tuple<std::vector<int>, bool>> {
    };

    // Define the test using the parameterized fixture
    TEST_P(P0055JumpGameTest, Testcases) {
        std::vector<int> input = std::get<0>(GetParam());
        const bool expectedResult = std::get<1>(GetParam());

        Solution solution;
        const bool result = solution.canJump(input);

        ASSERT_EQ(result, expectedResult);
    }

    INSTANTIATE_TEST_SUITE_P(LeedCode, P0055JumpGameTest,
                             testing::Values(
                                 std::make_tuple(std::vector<int>{2, 3, 1, 1, 4}, true),
                                 std::make_tuple(std::vector<int>{3, 2, 1, 0, 4}, false),
                                 std::make_tuple(std::vector<int>{2, 0}, true),
                                 std::make_tuple(std::vector<int>{2, 5, 0, 0}, true)
                             )
    );
}
