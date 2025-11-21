// something to note, this solution I came up with is a little messy, but it works
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int i,j;
        i = 0;
        j = 0;

        // if there is a swap increment both ptrs, else just increment j
        // end condition is when j reaches last element
        while(j < sz) {
            if(nums[i] == 0 && nums[j] != 0) {
                // swap
                int temp = nums[j];
                nums[i] = temp;
                nums[j] = 0;
                j++;
                i++;
                continue;
            } else if(nums[i] != 0) {
               i++;
               j++;
            } else {
                j++;
            }
        }

    }
};