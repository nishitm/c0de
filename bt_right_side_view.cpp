// problem::Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node {
    TreeNode* treeNode;
    int depth;
    Node(TreeNode* n, int d): treeNode(n), depth(d) { }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        map<int, int> m;
        queue<Node> q;
        q.push(Node(root, 0));
        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            auto& v = m[n.depth];
            v = n.treeNode->val;
            if (n.treeNode->left) {
                q.push(Node(n.treeNode->left, n.depth + 1));
            }
            if (n.treeNode->right) {
                q.push(Node(n.treeNode->right, n.depth + 1));
            }
        }
        for (const auto& it: m) {
            result.push_back(it.second);
        }
        return result;
    }
};
