class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        // build hash map of keys and counts
        unordered_map<int, int> counts; 
        
        int sz = nums.size();
        
        for(int i = 0; i < sz; i++) {
            counts[nums[i]]++;
        }
        
        int ans = -1;
        
        for(const auto& pair: counts) {
            if(pair.first > ans && pair.second == 1) {
                ans = max(ans, pair.first);
            }
        }
        
        return ans;
        
    }
};