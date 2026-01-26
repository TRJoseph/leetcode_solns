class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // first get the boxtype size
        int sz = boxTypes.size();
        
        // this should be unit per box, then number of boxes
        // we want to greedily select the highest unit per box
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < sz; i++) {
            int unitsPerBox = boxTypes[i][1];
            int boxCount = boxTypes[i][0];
            
            pq.push({unitsPerBox, boxCount});
        }
        
        int maxUnits = 0;
        
        while(!pq.empty()) {
            // units per box, box count
            pair<int, int> boxPair = pq.top();
            pq.pop();
            int boxCount = boxPair.second;
            while(boxCount > 0) {
                if(boxCount <= truckSize) {
                    maxUnits += boxCount * boxPair.first;
                    truckSize -= boxCount;
                    break;
                }
                boxCount--;
            }
        }
        
        return maxUnits;
    }
};