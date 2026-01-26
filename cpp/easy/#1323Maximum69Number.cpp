class Solution {
public:
    int maximum69Number (int num) {
        // greedily try to change the leftmost 6 into a 9 to increase the maximum number
        
        stack<int> digits;
        
        while(num != 0) {
            digits.push(num % 10);
            num /= 10;
        }
        
        int ans = 0;
        bool hasReplaced = false;
        
        while(!digits.empty()) {
            int chosenNum = 0;
            
            if(digits.top() == 6 && !hasReplaced) {
                chosenNum = 9;
                hasReplaced = true;
            } else {
                chosenNum = digits.top();
            }
            
            digits.pop();
            ans += chosenNum;
            ans *= 10;
        }
        
        return ans / 10;
    }
};