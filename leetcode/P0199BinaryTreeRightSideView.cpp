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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> view;
            if (!root) return view;

            queue<TreeNode *> next_level;
            next_level.push(root);

            while (!next_level.empty()) {
                view.push_back(next_level.front()->val);
                queue current_level(move(next_level));
                next_level = queue<TreeNode *>();
                while (!current_level.empty()) {
                    const TreeNode* node = current_level.front();
                    current_level.pop();

                    if (node->right)
                        next_level.push(node->right);

                    if (node->left)
                        next_level.push(node->left);
                }
            }

            return view;
        }
    };
}

#include <gtest/gtest.h>

class P0199BinaryTreeRightSideViewTest : public testing::TestWithParam<std::tuple<TreeNode *, std::vector<int>>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0199BinaryTreeRightSideViewTest,
                         testing::Values(
                             std::make_tuple(new TreeNode{1,2,3,INT_MIN,5,INT_MIN,4}, std::vector<int>{1,3,4}),
                             std::make_tuple(new TreeNode{1,INT_MIN,3}, std::vector<int>{1,3}),
                             std::make_tuple(nullptr, std::vector<int>{})
                         )
);

TEST_P(P0199BinaryTreeRightSideViewTest, Testcases) {
    auto& input = std::get<0>(GetParam());
    const auto expected_output = std::get<1>(GetParam());

    p0199::Solution solution;
    const auto result = solution.rightSideView(input);

    ASSERT_EQ(result, expected_output);
}
