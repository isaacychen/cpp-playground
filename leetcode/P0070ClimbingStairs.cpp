//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>

using namespace std;

#include <map>

namespace p0070 {
    class Solution {
    private:
        std::map<int, int> cache;

    public:
        int climbStairs(int n) {
            if (cache.contains(n))
                return cache.at(n);

            if (n > 2)
                return cache[n] = climbStairs(n - 2) + climbStairs(n - 1);

            return n > 0 ? n : 0;

            // f(n) = f(n - 2) + f(n - 1)
            // f(1) = 1, f(2) = 2,
            //
            // if (n <= 2) return n;
            // int fn_minus_2 = 1;
            // int fn_minus_1 = 2;
            // int fn = 3;
            // for (int i = 4; i <= n; ++i) {
            //     fn_minus_2 = fn_minus_1;
            //     fn_minus_1 = fn;
            //     fn = fn_minus_2 + fn_minus_1;
            // }
            // return fn;
        }
    };
}

#include <gtest/gtest.h>

class P0070ClimbingStairsTest : public testing::TestWithParam<std::tuple<int, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0070ClimbingStairsTest,
                         testing::Values(
                             std::make_tuple(2, 2),
                             std::make_tuple(3, 3)
                         )
);

TEST_P(P0070ClimbingStairsTest, Testcases) {
    const int input = std::get<0>(GetParam());
    const int expected_output = std::get<1>(GetParam());

    p0070::Solution solution;
    const int output = solution.climbStairs(input);

    ASSERT_EQ(output, expected_output);
}
