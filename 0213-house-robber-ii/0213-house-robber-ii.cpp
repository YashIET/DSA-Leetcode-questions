class Solution {
public:
    typedef int ll;
    ll rec(ll i,vector<ll>&v,vector<ll>&dp){
        if(i==0)return v[i];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        ll pick=v[i]+rec(i-2,v,dp);
        pick=max(pick,rec(i-1,v,dp));
        return dp[i] = pick;
    }
    int rob(vector<int>& nums) {
        vector<ll>v1,v2;
        ll n=nums.size();
        vector<ll>dp1(n-1,-1),dp2(n-1,-1);
       
        for(ll i=0;i<n-1;i++){
            v1.push_back(nums[i]);
        }
        for(ll i=1;i<n;i++){
            v2.push_back(nums[i]);
        }
        if(n==1)return nums[0];
        return max(rec(v1.size()-1,v1,dp1),rec(v2.size()-1,v2,dp2));
    }
};