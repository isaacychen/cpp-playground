//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>

using namespace std;

#include <map>

namespace p0198 {
    class Solution {
    private:
        map<size_t, int> cache;

    public:
        int rob(vector<int>& nums) {
            // f(nums[0:n-1]) = max(f(nums[0:n-2]), f(nums[0:n-3]) + nums[n-1])
            // f({}) = 0
            // f(nums[0:0]) = nums[0]
            //
            //
            // if (nums.empty()) return 0;
            //
            // int l_max = 0;
            // int r_max = nums[0];
            // for (int i = 1; i < nums.size(); i++) {
            //     const int current = max(r_max, l_max + nums[i]);
            //     l_max = r_max;
            //     r_max = current;
            // }
            // return max(l_max, r_max);

            if (nums.size() < 2) {
                return nums.size() == 1 ? nums[0] : 0;
            }

            return robMax(nums, nums.size() - 1);
        }

        int robMax(vector<int>& nums, size_t i) {
            if (cache.contains(i)) {
                return cache.at(i);
            }
            if (i == 0) {
                return nums[0];
            }
            if (i == 1) {
                return max(nums[0], nums[1]);
            }
            return cache[i] = max(robMax(nums, i - 2) + nums[i], robMax(nums, i - 1));
        }
    };
}

#include <gtest/gtest.h>

class P0198HouseRobberTest : public testing::TestWithParam<std::tuple<vector<int>, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0198HouseRobberTest,
                         testing::Values(
                             std::make_tuple(std::vector<int>{1,2,3,1}, 4),
                             std::make_tuple(std::vector<int>{2,7,9,3,1}, 12)
                         )
);

TEST_P(P0198HouseRobberTest, Testcases) {
    auto input = std::get<0>(GetParam());
    const int expected_output = std::get<1>(GetParam());

    p0198::Solution solution;
    const int output = solution.rob(input);

    ASSERT_EQ(output, expected_output);
}
