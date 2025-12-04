#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long distanceTraveled(const string& instructions) {
        // initialize position and speed, we start at position 0 and speed 1
        int currPos = 0;
        int prevPos = 0;
        int speed = 1;
        int direction = 1;
        int total_travelled = 0;
        
        int sz = instructions.size();

        
        // iterate over each instruction
        for(int i = 0; i < sz; i++) {
            if (instructions[i] == 'A') {
                currPos += direction * speed;
                speed *= 2;
            } else if(instructions[i] == 'R') {
                // speed at 1, and reverse direction
                speed = 1;
                direction *= -1;
            } else {
                // do nothing
            }
            
            total_travelled += abs(currPos - prevPos);
            prevPos = currPos;
        }
        
        
        // return the total distance moved
        return total_travelled; // placeholder
    }
};

int main() {
    Solution sol;
    string s = "RRRR";

    // read input string
    //cin >> s;

    // call the function

    cout << sol.distanceTraveled(s) << endl;
    return 0;
}
