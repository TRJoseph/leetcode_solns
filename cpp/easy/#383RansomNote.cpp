class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomMap;
        
        for(char& ch: ransomNote) {
            ransomMap[ch]++;
        }
        
        for(char& ch: magazine) {
            if(ransomMap.contains(ch)) {
                ransomMap[ch]--;
                if(ransomMap[ch] == 0) {
                    ransomMap.erase(ch);
                }
            }
        }
        
        return ransomMap.empty();
    }
};