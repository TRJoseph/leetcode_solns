class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // we want to be able to access
        priority_queue<int,vector<int>> maxHeap(piles.begin(), piles.end());
        
        while(!maxHeap.empty() && k > 0) {
            int top = maxHeap.top();
            maxHeap.pop();
            top = top - top / 2;
            maxHeap.push(top);
            k--;
        }
        
        int minSum = 0;
        
        // O(nlogn) term dominates
        while(!maxHeap.empty()){
            minSum += maxHeap.top();
            maxHeap.pop();
        }
        
        return minSum;
    }
};