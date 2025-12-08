/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int recurse(TreeNode* currNode, int val) {
        // base cases
        if(currNode == nullptr) {
            return 0;
        }

        int goodNodes = 0;
        goodNodes += recurse(currNode->left, max(currNode->val, val));
        goodNodes += recurse(currNode->right, max(currNode->val, val));

        if(currNode->val >= val) {
            return goodNodes + 1;
        } else {
            return goodNodes;
        }
    }

public:
    int goodNodes(TreeNode* root) {
        return recurse(root, root->val);
    }
};