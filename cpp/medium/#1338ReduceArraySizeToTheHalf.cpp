class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // this will be <number, count>
        int originalSz = arr.size();
        unordered_map<int, int> counts;
        
        for(int& num : arr) {
            counts[num]++;
        }
        
        vector<int> freqs;
        
        for(auto& [key, value] : counts) {
            freqs.push_back(value);
        }
        
        sort(freqs.begin(), freqs.end());
        
        int removes = 0;
        int freqIdx = freqs.size()-1;
        int currSz = originalSz;
        
        // greedily remove the most common occurrence until the size is at least half
        while(currSz > originalSz / 2) {
            currSz -= freqs[freqIdx];
            freqs.pop_back();
            removes++;
            freqIdx--;
        }
        
        return removes;
    }
};