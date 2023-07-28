class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll buy,ll cap,vector<ll>&prices,vector<vector<vector<ll>>>&dp){
        if(cap==0)return 0;
        if(i==prices.size())return 0;
        
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        ll profit=0;
        
        if(buy)profit=max(-prices[i]+rec(i+1,0,cap,prices,dp),rec(i+1,1,cap,prices,dp));
        else profit=max(prices[i]+rec(i+1,1,cap-1,prices,dp),rec(i+1,0,cap,prices,dp));
        
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        ll n=prices.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,vector<ll>(3,-1)));
        return rec(0,1,2,prices,dp);
    }
};