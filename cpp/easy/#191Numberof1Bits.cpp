class Solution {
public:
    int hammingWeight(int n) {
        int weight = 0;

        while (n != 0) {
            // shift bits out and add to weight
            if((n & 1) == 1) {
                weight+=1;
            }
            n >>= 1;
        }

        return weight;

    }
};