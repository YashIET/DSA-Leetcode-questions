typedef int ll;
class MedianFinder {
    priority_queue<long long>small,large;
public:
    // https://leetcode.com/problems/find-median-from-data-stream/discuss/74062/Short-simple-JavaC%2B%2BPython-O(log-n)-%2B-O(1)
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size()<large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size()>large.size() ? small.top():(small.top()-large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */