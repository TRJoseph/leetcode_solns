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
public:

    int recurse(TreeNode* node, int depth) {

        // base case
        if(node->left == nullptr && node->right == nullptr) {
            return depth;
        }

        int leftDepth = depth;
        int rightDepth = depth;
        
        if(node->left != nullptr) {
            leftDepth = recurse(node->left, leftDepth + 1);
        }
        if(node->right != nullptr) {
            rightDepth = recurse(node->right, rightDepth + 1);
        }

        return max(leftDepth, rightDepth);
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } else {
            return recurse(root, 1);
        }
        
    }
};