class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll n,vector<ll>&dp){
        if(i>n)return  0;
        if(i==n)return dp[i]= 1;
        if(dp[i]!=-1)return dp[i];
        return dp[i]= rec(i+1,n,dp)+rec(i+2,n,dp);
    }
    int climbStairs(int n) {
        vector<ll>dp(n+1,-1);
        return rec(0,n,dp);
    }
};