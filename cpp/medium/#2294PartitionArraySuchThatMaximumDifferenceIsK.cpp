class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;
        int ans = 1;

        while(right < nums.size()) {
           if(nums[right] - nums[left] <= k) {
                right++;
           } else {
                ans ++;
                left = right;
           }
        }
        return ans;
    }
};