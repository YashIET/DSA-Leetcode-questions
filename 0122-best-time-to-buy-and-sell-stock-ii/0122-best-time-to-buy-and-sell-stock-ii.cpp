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
        else profit=max(prices[i]+rec(i+1,1,prices,dp),rec(i+1,0,prices,dp));
        
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        ll n=prices.size();
        vector<vector<ll>>dp(prices.size()+1,vector<ll>(2,-1));
        dp[n][0]=0,dp[n][1]=0;
        for(ll i=n-1;i>=0;i--){
            for(ll buy=0;buy<=1;buy++){
                if(buy){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};