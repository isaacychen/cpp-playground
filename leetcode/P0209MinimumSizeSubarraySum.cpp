//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>

using namespace std;

namespace p0042 {
    class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            auto right_it = nums.begin();
            auto left_it = nums.begin();
            int sum = 0;
            ptrdiff_t min_length = PTRDIFF_MAX;
            for (; right_it != nums.end(); ++right_it) {
                sum += *right_it;
                for (; sum >= target; ++left_it) {
                    min_length = min(
                        min_length,
                        distance(left_it, right_it) + 1
                    );
                    sum -= *left_it;
                }
            }
            return static_cast<int>(min_length == PTRDIFF_MAX ? 0 : min_length);
        }
    };
}

#include <gtest/gtest.h>

class P0209MinimumSizeSubarraySumTest : public testing::TestWithParam<std::tuple<int, std::vector<int>, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0209MinimumSizeSubarraySumTest,
                         testing::Values(
                             std::make_tuple(7, std::vector<int>{2,3,1,2,4,3}, 2),
                             std::make_tuple(4, std::vector<int>{1,4,4}, 1),
                             std::make_tuple(11, std::vector<int>{1,1,1,1,1,1,1,1}, 0)
                         )
);

TEST_P(P0209MinimumSizeSubarraySumTest, Testcases) {
    const int target = std::get<0>(GetParam());
    std::vector<int> nums = std::get<1>(GetParam());
    const int expected_output = std::get<2>(GetParam());

    p0042::Solution solution;
    const int result = solution.minSubArrayLen(target, nums);

    ASSERT_EQ(result, expected_output);
}
