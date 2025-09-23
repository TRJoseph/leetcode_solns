class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDiff = 0;
        int currentMin;

        if(prices.size() > 1) {
            currentMin = prices[0];
        }
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < currentMin) {
                currentMin = prices[i];
            }

            if(prices[i] - currentMin > maxDiff) {
                maxDiff = prices[i] - currentMin;
            }
        }


        return maxDiff;

    }
};