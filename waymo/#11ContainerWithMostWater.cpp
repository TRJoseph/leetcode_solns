class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int sz = height.size();
        int i = 0;
        int j = sz-1;

        while(i != j) {
            int minCont = min(height[i], height[j]);
            int currArea = (j-i) * minCont;

            if(currArea > maxWater) {
                maxWater = currArea;
            }

            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxWater;

    }
};