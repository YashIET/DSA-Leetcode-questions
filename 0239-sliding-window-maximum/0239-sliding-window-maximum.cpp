class Solution {
public:
    typedef int ll;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<ll>ans;
        map<ll,ll>m;
        // ll last=(m.rbegin()->first);
        for(ll i=0;i<k;i++)m[nums[i]]++;
        ans.push_back(m.rbegin()->first);
        if(k>=n){return ans;}
        for(ll i=k;i<n;i++){
            m[nums[i-k]]--;
            if(m[nums[i-k]]==0)m.erase(nums[i-k]);
            m[nums[i]]++;
            ans.push_back(m.rbegin()->first);
        }
        return ans;
    }
};