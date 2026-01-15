// This problem was a greedy problem where we greedily select the heaviest person on the boat and the least heavy and pair them together to attempt to get under the weight limit for the least number of boats
// my algorithm runs in O(n log n) because it is necessary to sort the list to have quick access to the heaviest and lightest person

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size()-1;
        int ans = 0;

        while(left < right) {
            int weight = people[right] + people[left];
            if(weight > limit) {
                // we need a single boat for the heaviest person
                ans++;
                right--;
            }

            if(weight <= limit) {
                right--;
                left++;
                ans++;
            }
        }

        // since individual weight is guaranteed to be less than limit
        if(left == right) {
            ans++;
        }

        return ans;
    }
};