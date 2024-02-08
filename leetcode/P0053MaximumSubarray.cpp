//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>

using namespace std;

namespace p0053 {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // f(nums[0:n-1]) = max(f(nums[0:n-2]), f(nums[0:n-2]) + nums[n-1], nums[n-1])
            // f(nums[0:0]) = nums[0];
            if (nums.empty()) return 0;

            int max_prefix = nums[0];
            int max_sum = nums[0];
            for (size_t i = 1; i < nums.size(); ++i) {
                max_prefix = max(max_prefix + nums[i], nums[i]);
                max_sum = max(max_sum, max_prefix);
            }

            return max_sum;
        }
    };
}

#include <gtest/gtest.h>

class P0053MaximumSubarrayTest : public testing::TestWithParam<std::tuple<std::vector<int>, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0053MaximumSubarrayTest,
                         testing::Values(
                             std::make_tuple(std::vector<int>{-2,1,-3,4,-1,2,1,-5,4}, 6),
                             std::make_tuple(std::vector<int>{1}, 1),
                             std::make_tuple(std::vector<int>{5,4,-1,7,8}, 23)
                         )
);

TEST_P(P0053MaximumSubarrayTest, Testcases) {
    auto input = std::get<0>(GetParam());
    const int expected_output = std::get<1>(GetParam());

    p0053::Solution solution;
    const int result = solution.maxSubArray(input);

    ASSERT_EQ(result, expected_output);
}
