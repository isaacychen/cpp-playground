//
// Created by isaac on 1/25/2024.
//

#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

namespace p0088 {
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            ranges::copy(nums2, nums1.begin() + m);
            ranges::inplace_merge(nums1, nums1.begin() + m);
        }
    };
}

#include <gtest/gtest.h>

TEST(P0088MergeSortedArray, Test1) {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;

    p0088::Solution solution;
    solution.merge(nums1, m, nums2, n);

    std::vector<int> expected = {1, 2, 2, 3, 5, 6};
    ASSERT_EQ(nums1, expected);
}

TEST(P0088MergeSortedArray, Test2) {
    std::vector<int> nums1 = {1};
    int m = 1;
    std::vector<int> nums2 = {};
    int n = 0;

    p0088::Solution solution;
    solution.merge(nums1, m, nums2, n);

    std::vector<int> expected = {1};
    ASSERT_EQ(nums1, expected);
}

TEST(P0088MergeSortedArray, Test3) {
    std::vector<int> nums1 = {0};
    int m = 0;
    std::vector<int> nums2 = {1};
    int n = 1;

    p0088::Solution solution;
    solution.merge(nums1, m, nums2, n);

    std::vector<int> expected = {1};
    ASSERT_EQ(nums1, expected);
}
