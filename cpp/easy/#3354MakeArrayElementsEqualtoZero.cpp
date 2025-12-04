class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        // try each 0 from starting vector
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                // start search
                int curr = i;
                movementStep = 1;
                while(curr > 0 && curr < nums.size() - 1) {
                    if(nums[curr] > 0) {
                        nums[curr] -= 1;
                        movementStep = -1;
                    }
                    curr += movementStep;
                }
            }
        }
    }
};