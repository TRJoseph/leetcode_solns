#include <queue>
class RecentCounter {
public:
    int counter;
    std::queue<int> requests;
    RecentCounter() {
        counter = 0;
    }
    
    int ping(int t) {
        if(requests.empty()) {
            requests.push(t);
            return 1;
        }

        requests.push(t);

        while(!requests.empty() && requests.front() < t - 3000) {
            // go through the queue checking range
            requests.pop();
        }

        return requests.size();

    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */