//
// Created by isaac on 1/28/2024.
//

#include <vector>

using namespace std;

namespace p0121 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() < 2) return 0;
            auto maxProfit = prices[1] > prices[0] ? prices[1] - prices[0] : 0;
            auto& minPrice = prices[1] < prices[0] ? prices[1] : prices[0];
            for (auto it = prices.begin() + 2; it != prices.end(); ++it) {
                if (minPrice > *it)
                    minPrice = *it;
                maxProfit = max(maxProfit, *it - minPrice);
            }
            return maxProfit;
        }
    };
}
