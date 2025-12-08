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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        vector<int> rightSideView;

        while(!nodes.empty()) {
            int nodesAtCurrLevel = nodes.size();

            rightSideView.push_back(nodes.front()->val);

            // everytime we are on the front item in the queue
            for(int i = 0; i < nodesAtCurrLevel; i++) {
                TreeNode* ref = nodes.front(); // get the current front node
                nodes.pop();
                
                // push right value first to make sure it appears at the front of the queue (learned that this is not optimal actually,
                // instead it is better to just push the 'last node' when ordered from left to right with an extra condition inside this
                // for loop)
                if(ref->right) {
                    nodes.push(ref->right);
                }

                if(ref->left) {
                    nodes.push(ref->left);
                }

            }
        }

        return rightSideView;
    }
};