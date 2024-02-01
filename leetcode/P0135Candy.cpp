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
        int candy(vector<int>& ratings) {
            if (ratings.empty()) return 0;
            if (ratings.size() < 2) return 1;

            vector<int> lDiffs(ratings.size(), 1), rDiffs(ratings.size(), 1);

            adjacent_difference(ratings.begin(), ratings.end(), lDiffs.begin());
            adjacent_difference(ratings.rbegin(), ratings.rend(), rDiffs.rbegin());

            lDiffs.front() = 1;
            rDiffs.back() = 1;

            const auto accumulate = [](auto acc, auto n) {
                return n <= 0 ? 1 : acc + 1;
            };

            partial_sum(lDiffs.begin(), lDiffs.end(), lDiffs.begin(), accumulate);
            partial_sum(rDiffs.rbegin(), rDiffs.rend(), rDiffs.rbegin(), accumulate);

            int sum = 0;
            for (int i = 0; i < ratings.size(); ++i) {
                sum += max(lDiffs[i], rDiffs[i]);
            }

            return sum;

            // Only traverse once.
            //
            // if (ratings.empty()) return 0;
            // if (ratings.size() == 1) return 1;
            // int sum = ratings[1] == ratings[0] ? 2 : 3;
            // int lastDiff = ratings[1] - ratings[0];
            // int quality = ratings[1] == ratings[0] ? 1 : 2;
            // int up = ratings[1] > ratings[0] ? 1 : 0;
            // int down = 0;
            // for (int i = 2; i < ratings.size(); i++) {
            //     int diff = ratings[i] - ratings[i - 1];
            //     if (diff == 0) {
            //         quality = 1;
            //         sum += quality;
            //         if (lastDiff != 0) {
            //             if (down - up > 0) {
            //                 sum += (down - up);
            //             }
            //             down = 0;
            //             up = 0;
            //         }
            //     } else if (diff > 0) {
            //         if (lastDiff < 0) {
            //             quality = 2;
            //             sum += quality;
            //             if (down - up > 0) {
            //                 sum += (down - up);
            //             }
            //             down = 0;
            //             up = 1;
            //         } else {
            //             sum += ++quality;
            //             up++;
            //         }
            //     } else if (diff < 0) {
            //         if (lastDiff <= 0) {
            //             sum += ++quality;
            //         } else {
            //             quality = 1;
            //             sum += quality;
            //         }
            //         if (lastDiff != 0) {
            //             if (up > 0) {
            //                 down++;
            //             }
            //         }
            //     }
            //     lastDiff = diff;
            // }
            // if (down - up > 0) {
            //     sum += (down - up);
            // }
            // return sum;
        }
    };
}

#include <gtest/gtest.h>

// Define a test fixture
class P0135CandyTest : public testing::TestWithParam<std::tuple<std::vector<int>, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0135CandyTest,
                         testing::Values(
                             std::make_tuple(std::vector<int>{1,0,2}, 5),
                             std::make_tuple(std::vector<int>{1,2,2}, 4),
                             std::make_tuple(std::vector<int>{1,3,2,2,1}, 7),
                             std::make_tuple(std::vector<int>{1,6,10,8,7,3,2}, 18),
                             std::make_tuple(std::vector<int>{1,2,87,87,87,2,1}, 13),
                             std::make_tuple(std::vector<int>{0,1,2,5,3,2,7}, 15)
                         )
);

TEST_P(P0135CandyTest, Testcases) {
    std::vector<int> input = std::get<0>(GetParam());
    const int expected_output = std::get<1>(GetParam());

    p0135::Solution solution;
    const int result = solution.candy(input);

    ASSERT_EQ(result, expected_output);
}
