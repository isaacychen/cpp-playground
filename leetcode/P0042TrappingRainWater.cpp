//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>

using namespace std;

namespace p0135 {
    class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.size() < 2) return 0;

            vector<int> left_shadow(height.size(), height.front()), right_shadow(height.size(), height.back());

            for (size_t i = 1; i < height.size(); ++i)
                left_shadow[i] = max(height[i], left_shadow[i - 1]);

            for (size_t i = height.size() - 1; i > 0; --i)
                right_shadow[i - 1] = max(height[i - 1], right_shadow[i]);

            int water = 0;
            for (size_t i = 0; i < height.size(); ++i) {
                water += min(left_shadow[i], right_shadow[i]) - height[i];
            }

            return water;

            // int l = 0, r = height.size() - 1, lmax = INT_MIN, rmax = INT_MIN, ans = 0;
            // while (l < r) {
            //     lmax = max(lmax, height[l]);
            //     rmax = max(rmax, height[r]);
            //     ans += (lmax < rmax) ? lmax - height[l++] : rmax - height[r--];
            // }
            // return ans;
        }
    };
}

#include <gtest/gtest.h>

class P0042TrappingRainWaterTest : public testing::TestWithParam<std::tuple<std::vector<int>, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0042TrappingRainWaterTest,
                         testing::Values(
                             std::make_tuple(std::vector<int>{0,1,0,2,1,0,1,3,2,1,2,1}, 6),
                             std::make_tuple(std::vector<int>{4,2,0,3,2,5}, 9)
                         )
);

TEST_P(P0042TrappingRainWaterTest, Testcases) {
    std::vector<int> input = std::get<0>(GetParam());
    const int expected_output = std::get<1>(GetParam());

    p0135::Solution solution;
    const int result = solution.trap(input);

    ASSERT_EQ(result, expected_output);
}
