//
// Created by isaac on 1/28/2024.
//

#include <numeric>
#include <vector>
#include <ranges>

using namespace std;

namespace p0121 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() < 2) return 0;

            // int maxProfit = 0;
            // for (auto i = 0; i != prices.size() - 1; ++i) {
            //     if (const auto diff = prices[i + 1] - prices[i]; diff > 0) {
            //         maxProfit += diff;
            //     }
            // }
            //
            // return maxProfit;

            auto growthDiffs = views::iota(0u, prices.size() - 1) |
                               views::transform([&prices](const auto i) { return prices[i + 1] - prices[i]; }) |
                               views::filter([](const auto i) { return i > 0; }) |
                               views::common;

            return accumulate(growthDiffs.begin(), growthDiffs.end(), 0);
        }
    };
}
