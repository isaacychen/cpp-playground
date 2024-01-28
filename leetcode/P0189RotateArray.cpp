//
// Created by isaac on 1/27/2024.
//

#include <vector>

using namespace std;

namespace p0189 {
    class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if (nums.size() < 2) return;

            k = static_cast<int>(k % nums.size());
            reverse(nums.begin(), nums.end() - k);
            reverse(nums.end() - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    };
}

#include <gtest/gtest.h>

// Define a test fixture
class P0189RotateArrayTestcase : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {
};

// Define the parameterized test suite
INSTANTIATE_TEST_SUITE_P(P0189, P0189RotateArrayTestcase,
                         ::testing::Values(
                             // Test case 1
                             std::make_tuple(std::vector<int>{1, 2, 3, 4, 5, 6, 7}, 3, std::vector<int>{5, 6, 7, 1, 2, 3
                                 , 4}),

                             // Test case 2
                             std::make_tuple(std::vector<int>{-1, -100, 3, 99}, 2, std::vector<int>{3, 99, -1, -100})
                         )
);

// Define the test using the parameterized fixture
TEST_P(P0189RotateArrayTestcase, Examples) {
    // Arrange
    std::vector<int> input = std::get<0>(GetParam());
    const int k = std::get<1>(GetParam());
    const std::vector<int> expected_output = std::get<2>(GetParam());

    // Act
    p0189::Solution solution;
    solution.rotate(input, k); // Assuming you have a rotate function

    // Assert
    ASSERT_EQ(input, expected_output);
}
