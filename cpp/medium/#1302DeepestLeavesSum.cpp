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
    int maxDepth;
    
    int dfsDepth(TreeNode* curr) {
        if(curr == nullptr) {
            return 0;
        }
        
        int leftSum = dfsDepth(curr->left) + 1;
        int rightSum = dfsDepth(curr->right) + 1;
        
        return max(leftSum, rightSum);
    }
    
    int dfsSum(TreeNode* curr, int currDepth) {
        if(curr == nullptr) {
            return 0;
        }
        
        if(currDepth == maxDepth) {
            return curr->val;
        }
        
        int sum = 0;
        // go left
        sum += dfsSum(curr->left, currDepth+1);
        // go right
        sum += dfsSum(curr->right, currDepth+1);
        
        return sum;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        maxDepth = dfsDepth(root);
        return dfsSum(root, 1);
    }
};