class KthLargest {
    
    public:
    // https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/1924721/C%2B%2BJavaPython-optimum-solution-approach-Start-here-if-this-is-your-first-heap-problem
    typedef int ll;
    ll idx;
    priority_queue<ll,vector<ll>,greater<ll>>pq;//declaration for min heap

    KthLargest(int k, vector<int>& nums) {
        idx=k;
        for(auto i:nums){
            add(i);
        }
    }
    
    int add(int val) {
        if(pq.size()<idx)pq.push(val);
        else {
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */