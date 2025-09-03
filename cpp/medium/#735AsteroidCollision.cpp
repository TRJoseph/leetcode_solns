class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for(int i = 0; i < asteroids.size(); i ++) {
            
            while(true) {
                if (asteroids[i] < 0 && stack.size() > 0 && stack.back() > 0) {
                    if (-asteroids[i] > stack.back()) {
                        stack.pop_back();
                        continue;
                    } else if (-asteroids[i] == stack.back()) {
                        stack.pop_back();
                        break;
                    }
                    break;
                } else {
                    stack.push_back(asteroids[i]);
                    break;
                }
            }
        }

        return stack;
    }
};