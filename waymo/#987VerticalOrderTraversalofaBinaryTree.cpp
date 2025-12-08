// first real attempt at a leetcode hard. I need to implement some sort of hashmap 
// like <int, pair<int,int>> where the key is the column and the <int, int> is <row, value>

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

struct NodeState {
    TreeNode* node;
    int row;
    int col;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<NodeState> nodes;
        // 0th row, 0th col at start
        NodeState rootState {root, 0, 0};
        // we know the input guaranteed to have one node so we can safely push
        nodes.push(rootState);

        vector<vector<int>> ans;

        while(!nodes.empty()) {
            int currentLevelCount = nodes.size();
            vector<int> levelNodes;

            for(int i = 0; i < currentLevelCount; i++) {
                NodeState ref = nodes.front();
                nodes.pop();

                if(ref.node->left) {
                    NodeState leftState {ref.node->left, ref.row+1, ref.col-1};
                    nodes.push(leftState);
                }

                if(ref.node->right) {
                    NodeState rightState {ref.node->right, ref.row+1, ref.col+1};
                    nodes.push(rightState);
                }

                levelNodes.push_back(ref.node->val);
            }
            ans.push_back(levelNodes);
        }

        return ans;

    }
};