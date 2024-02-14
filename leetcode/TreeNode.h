//
// Created by isaac on 2/13/2024.
//

#ifndef TREENODE_H
#define TREENODE_H
#include <initializer_list>
#include <queue>

using namespace std;

namespace cppp {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        // // unique_ptr<TreeNode> left;
        // // unique_ptr<TreeNode> right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {
        }

        TreeNode(initializer_list<int> list) {
            if (list.size() == 0) return;

            auto it = list.begin();
            val = *it++;

            queue<TreeNode *> q;
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
}

#endif //TREENODE_H
