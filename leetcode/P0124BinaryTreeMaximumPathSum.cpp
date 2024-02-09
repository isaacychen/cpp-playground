//
// Created by isaac on 1/31/2024.
//

#include <numeric>
#include <vector>
#include <ranges>
#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

namespace p0124 {
    /**
     * Definition for a binary tree node.
     */
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        // // unique_ptr<TreeNode> left;
        // // unique_ptr<TreeNode> right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {
        }

        TreeNode(initializer_list<int> list) {
            if (empty(list)) return;

            auto it = list.begin();
            val = *it++;

            std::queue<TreeNode *> q;
            q.push(this);

            while (it != list.end()) {
                TreeNode* curr = q.front();
                q.pop();

                if (*it != INT_MIN) {
                    curr->left = new TreeNode(*it);
                    q.push(curr->left);
                }
                ++it;

                if (it != list.end() && *it != INT_MIN) {
                    curr->right = new TreeNode(*it);
                    q.push(curr->right);
                }
                ++it;
            }
        }

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }

        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {
        }

        // todo: Fix memory leak.
        //
        // ~TreeNode() {
        //     // Recursively delete left subtree
        //     if (left != nullptr) {
        //         delete left;
        //         left = nullptr;
        //     }
        //
        //     // Recursively delete right subtree
        //     if (right != nullptr) {
        //         delete right;
        //         right = nullptr;
        //     }
        // }
    };

    // todo: This is a bad solution.
    class Solution {
        map<const TreeNode*, int> sum_cache;
        map<const TreeNode*, int> side_sum_cache;
    public:
        int maxPathSum(TreeNode* root) {
            // f(t) = max(fp(t.left)+fp(t.right)+t.val, f(t.leaf):0, f(t.right):0)
            // f(t_leaf) = t_leaf.val
            // fp(t) = max(fp(t.left):0+val, fp(t.right):0+t.val)
            // fp(t_leaf) = t_leaf.val
            if (sum_cache.contains(root)) {
                return sum_cache.at(root);
            }

            if (!root->left && !root->right) {
                return root->val;
            }

            return sum_cache[root] = max({
                root->val,
                root->val + maxOfOneSide(root->left),
                root->val + maxOfOneSide(root->right),
                root->val + maxOfOneSide(root->left) + maxOfOneSide(root->right),
                root->left ? maxPathSum(root->left) : INT_MIN,
                root->right ? maxPathSum(root->right) : INT_MIN
            });
        }

        int maxOfOneSide(const TreeNode* root) {
            if (side_sum_cache.contains(root)) {
                return side_sum_cache.at(root);
            }
            if (!root) {
                return 0;
            }
            return side_sum_cache[root] = max({
                root->val,
                root->val + maxOfOneSide(root->left),
                root->val + maxOfOneSide(root->right)
            });
        }
    };
}

#include <gtest/gtest.h>

class P0124BinaryTreeMaximumPathSumTest : public testing::TestWithParam<std::tuple<p0124::TreeNode, int>> {
};

INSTANTIATE_TEST_SUITE_P(LeedCode, P0124BinaryTreeMaximumPathSumTest,
                         testing::Values(
                             std::make_tuple(p0124::TreeNode{1,2,3}, 6),
                             std::make_tuple(p0124::TreeNode{-10,9,20,INT_MIN,INT_MIN,15,7}, 42),
                             std::make_tuple(p0124::TreeNode{1,2,INT_MIN}, 3)
                         )
);

TEST_P(P0124BinaryTreeMaximumPathSumTest, Testcases) {
    auto input = std::get<0>(GetParam());
    const int expected_output = std::get<1>(GetParam());

    p0124::Solution solution;
    const int result = solution.maxPathSum(&input);

    ASSERT_EQ(result, expected_output);
}
