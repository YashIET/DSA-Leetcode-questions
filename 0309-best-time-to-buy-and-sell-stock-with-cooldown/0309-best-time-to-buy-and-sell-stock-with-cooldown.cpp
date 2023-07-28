class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll buy,vector<ll>&prices,vector<vector<ll>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        
        ll profit=0;
        if(buy){
            profit=max(-prices[i]+rec(i+1,0,prices,dp),rec(i+1,1,prices,dp));
        }
        else{
            profit=max(prices[i]+rec(i+2,1,prices,dp),rec(i+1,0,prices,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<ll>>dp(prices.size(),vector<ll>(2,-1));
        return rec(0,1,prices,dp);
    }
};