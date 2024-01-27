//
// Created by isaac on 1/26/2024.
//

#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        const auto &size = nums.size();
        if (size <= 2) {
            return static_cast<int>(size);
        }

        size_t j = 2;
        for (size_t i = 2; i < size; i++) {
            if (nums[i] != nums[i - 1] || nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return static_cast<int>(j);
    }
};
