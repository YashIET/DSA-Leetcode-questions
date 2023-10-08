typedef int ll;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>ans(n,1);
        for(ll i=0,pre=1,suff=1;i<n;i++){
            ans[i]*=pre;
            pre*=nums[i];
            ans[n-1-i]*=suff;
            suff*=nums[n-1-i];
        }
        return ans;
    
    }
};