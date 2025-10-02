class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int bottlesDrunk = 0;

        while(numBottles > 0 || emptyBottles >= numExchange) {

            if(numBottles > 0 && emptyBottles < numExchange) {
                // drink full bottles
                emptyBottles += numBottles;
                bottlesDrunk += numBottles;
                numBottles = 0;
                continue;
            }

            if(emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                // add one exchange and one full bottle
                numExchange += 1;
                numBottles += 1;
            }
        }

        return bottlesDrunk;
    }
};