class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll target,vector<ll>&coins,vector<vector<ll>>&dp){
        if(target==0)return 1;
        if(i==coins.size()-1){
            if(target%coins[i]==0)return 1;
            return 0;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        ll notTake=rec(i+1,target,coins,dp);
        ll take=0;
        if(target>=coins[i])take=rec(i,target-coins[i],coins,dp);
        
        return dp[i][target]=notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<ll>>dp(coins.size(),vector<ll>(amount+1,-1));
        return rec(0,amount,coins,dp);
    }
};