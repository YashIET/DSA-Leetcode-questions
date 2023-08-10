class Solution {
public:
    typedef int ll;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<ll>ans;
        deque<ll>dq;
        for(ll i=0;i<n;i++){
            while(!dq.empty()&&dq.front()==i-k)dq.pop_front();//check outof bound from left side
            
            while(!dq.empty() && nums[dq.back()]<=nums[i])dq.pop_back();//removes smaller ele 
            dq.push_back(i);
            if(i>=k-1)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};