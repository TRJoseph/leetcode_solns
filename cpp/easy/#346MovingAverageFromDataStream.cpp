class MovingAverage {
    int windowSz;
    queue<int> sizes;
    double runningSum;
public:
    MovingAverage(int size) {
        windowSz = size;
        runningSum = 0;
    }
    
    double next(int val) {
        
        sizes.push(val);
        runningSum += val;
        
        // ensure queue is not greater than the window size
        if(sizes.size() > windowSz) {
            runningSum -= sizes.front();
            sizes.pop();
        }
        
        return runningSum / static_cast<double>(sizes.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */