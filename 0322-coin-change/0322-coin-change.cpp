class Solution {
public:
    typedef int ll;
    ll rec(ll i, vector<int>& c, int amount,vector<vector<ll>>&dp){
        if(i==0){
            if(amount%c[i]==0){
                return amount/c[i];
            }
            else return 100000;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        //dont take current index coin
        ll noc=rec(i-1,c,amount,dp);
        //pick current and remain at current index because supply is infinite
        //also first check befor taki the coin if it can be picked or not
        if(amount-c[i]>=0)
        noc=min(noc,1+rec(i,c,amount-c[i],dp));
        
        return dp[i][amount]= noc;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<ll>>dp(coins.size(),vector<ll>(amount+1,-1));
        ll ans=rec(coins.size()-1,coins,amount,dp);
        if(ans==100000)return -1;
        return ans;
    }
};