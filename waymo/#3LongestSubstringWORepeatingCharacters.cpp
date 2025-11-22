class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int longestStr = 0;
        int currLen = 0;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            // if character is not in map, add it to map as <char, int> where int is the index of char
            if(!mp.contains(s[right])) {
                mp[s[right]] = right;

                // update longest currStr
                currLen = right + 1 - left;
                if(currLen > longestStr) longestStr = currLen;
                right++;
            } else {
                // reset left side of sliding window
                // continually remove past keys to update current window
                int leftStopIdx = mp.find(s[right])->second;
                while(left <= leftStopIdx) {
                    mp.erase(s[left]);
                    left++;
                }
            }
        }

        return longestStr;
    }
};