class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;

        int midpoint = 0;

        while (leftPtr <= rightPtr) {

            midpoint = leftPtr + ((rightPtr - leftPtr) / 2);
            if(nums[midpoint] == target) {
                return midpoint;
            }

            if(nums[leftPtr] <= nums[midpoint]) {
                // we figure out if we have to go right or left
                if(target > nums[midpoint] || target < nums[leftPtr]) {
                    // we need to go right to find target
                    leftPtr = midpoint+1;
                } else {
                    // it must be left
                    rightPtr = midpoint-1;
                }
            } else {
                if(target < nums[midpoint] || target > nums[rightPtr]) {
                    // we need to go left to find target
                    rightPtr = midpoint-1;
                } else {
                    // it must be right
                    leftPtr = midpoint+1;
                }
            }

        }

        return -1;

    }
};