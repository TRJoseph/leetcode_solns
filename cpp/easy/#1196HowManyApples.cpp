class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        // probably better to just sort the weights actually now that I think about it
        // would be O(n) space
        priority_queue<int,vector<int>,greater<int>> pq;
        int maxWeight = 5000;
        
        // n log n
        for(int& w : weight) {
            pq.push(w);
        }
        int appleCount = 0;
        
        while(maxWeight >= 0 && !pq.empty()) {
            int w = pq.top();
            pq.pop();
            if(maxWeight - w >= 0) {
                appleCount++;
            }
            maxWeight -= w;
        }
        
        return appleCount;
    }
};