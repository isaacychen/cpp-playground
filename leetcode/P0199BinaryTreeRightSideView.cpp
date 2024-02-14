//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>
#include <map>
#include "TreeNode.h"

using namespace cppp;
using namespace std;

namespace p0199 {
    class Solution {
    public:
        // todo: to be solved
        vector<int> rightSideView(TreeNode* root) {
            vector<int> view;
            if (!root) return view;
            view.push_back(root->val);

            for (TreeNode* r_child = root->right; r_child; r_child = r_child->right) {
                view.push_back(r_child->val);
            }

            return view;
        }
    };
}

#include <gtest/gtest.h>

class P0199BinaryTreeRightSideViewTest : public testing::TestWithParam<std::tuple<TreeNode, std::vector<int>>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0199BinaryTreeRightSideViewTest,
                         testing::Values(
                             std::make_tuple(TreeNode{1,2,3,INT_MIN,5,INT_MIN,4}, std::vector<int>{1,3,4}),
                             std::make_tuple(TreeNode{1,INT_MIN,3}, std::vector<int>{1,3})
                             // std::make_tuple(static_cast<TreeNode*>(nullptr), std::vector<int>{})
                         )
);

TEST_P(P0199BinaryTreeRightSideViewTest, Testcases) {
    auto input = std::get<0>(GetParam());
    const auto expected_output = std::get<1>(GetParam());

    p0199::Solution solution;
    const auto result = solution.rightSideView(&input);

    ASSERT_EQ(result, expected_output);
}
