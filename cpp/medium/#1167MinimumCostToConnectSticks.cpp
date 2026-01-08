class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> minHeap(sticks.begin(), sticks.end());
        
        int minCost = 0;
        // until one stick remains
        while(minHeap.size() > 1) {
            int firstStick = minHeap.top();
            minHeap.pop();
            int secondStick = minHeap.top();
            minHeap.pop();
            int tempSum = firstStick + secondStick;
            minHeap.push(tempSum);
            minCost += tempSum;
        }
        
        return minCost;
    }
};