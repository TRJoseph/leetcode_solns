class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for(int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        int j = 0;
        // O(nlogn)
        sort(projects.begin(), projects.end());
        priority_queue<int> maxHeap;

        // O(k*logn + nlogn)
        for(int i = 0; i < k; i++) {
            while(j < n && projects[j].first <= w) {
                maxHeap.push(projects[j].second);
                j++;
            }

            if(maxHeap.size() == 0) return w;

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};