class Solution {
public:
    //using priority queue;
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;//min heap
        auto it = nums.begin()+k;
        pq = priority_queue<int,vector<int>,greater<int>>(nums.begin(),it);
        for(int i=k;i<nums.size();i++){
            pq.push(nums[i]);
            pq.pop();
        }
        return pq.top();
        
    }
};