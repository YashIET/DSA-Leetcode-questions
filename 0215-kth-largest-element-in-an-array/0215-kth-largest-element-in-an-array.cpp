class Solution {
public:
    typedef int ll;
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(ll i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(ll i=k;i<nums.size();i++){
            
                
                pq.push(nums[i]);
                pq.pop();
            // pq.pop();
            // pq.push(nums[i]);
        }
        
        return pq.top();
    }
};