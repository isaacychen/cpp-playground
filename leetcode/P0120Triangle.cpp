//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>

using namespace std;

namespace p0120 {
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            // f(tri_n_m) = tri_n_m[0][0] + min(f(tri_n_m-1[0]), ..., f(tri_n_m-1[n-m])))
            // f(tri_n_0) = tri[0][0]
            return accumulate(
                triangle.rbegin(),
                triangle.rend(),
                vector(triangle.size() + 1, 0),
                [](auto acc, const auto& row) {
                    for (size_t i = 0; i < row.size(); ++i) {
                        acc[i] = row[i] + min(acc[i], acc[i + 1]);
                    }
                    return move(acc);
                })[0];
        }
    };
}

#include <gtest/gtest.h>

class P0120TriangleTest : public testing::TestWithParam<std::tuple<std::vector<std::vector<int>>, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0120TriangleTest,
                         testing::Values(
                             std::make_tuple(std::vector<std::vector<int>>{{2},{3,4},{6,5,7},{4,1,8,3}}, 11),
                             std::make_tuple(std::vector<std::vector<int>>{{-10}}, -10)
                         )
);

TEST_P(P0120TriangleTest, Testcases) {
    auto input = std::get<0>(GetParam());
    const int expected_output = std::get<1>(GetParam());

    p0120::Solution solution;
    const int result = solution.minimumTotal(input);

    ASSERT_EQ(result, expected_output);
}
