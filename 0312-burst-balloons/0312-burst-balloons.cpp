class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll j,vector<ll>&nums,vector<vector<ll>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        ll maxi=INT_MIN;
        for(ll ind=i;ind<=j;ind++){
            maxi=max(maxi,nums[i-1]*nums[ind]*nums[j+1]+rec(i,ind-1,nums,dp)+rec(ind+1,j,nums,dp));                
        }
        return dp[i][j]= maxi;
    }
    int maxCoins(vector<int>& nums) {
        ll n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
        return rec(1,n,nums,dp);
    }
};