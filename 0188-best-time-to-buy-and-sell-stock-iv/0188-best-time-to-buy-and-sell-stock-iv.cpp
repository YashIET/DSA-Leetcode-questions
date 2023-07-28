class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll buy,ll cap,vector<ll>&prices,vector<vector<vector<ll>>>&dp){
        if(cap==0 || i==prices.size())return 0;
        
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        
        ll profit=0;
        if(buy){
            profit=max(-prices[i]+rec(i+1,0,cap,prices,dp),rec(i+1,1,cap,prices,dp));
        }
        else{
            profit=max(prices[i]+rec(i+1,1,cap-1,prices,dp),rec(i+1,0,cap,prices,dp));
        }
        return dp[i][buy][cap]=profit;
    }
    
    
//     -------------iterative /  tabulation------------------------------------
    
    int maxProfit(int k, vector<int>& prices) {
        ll n=prices.size();
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(2,vector<ll>(k+1,0)));
        //i buy cap
        for(ll i=n-1;i>=0;i--){
            for(ll buy=0;buy<=1;buy++){
                for(ll cap=1;cap<=k;cap++){
                    //copied from memoized code
                    
         if(buy){
           dp[i][buy][cap] =max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
        }
        else{
            dp[i][buy][cap] =max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
        }
        
                    
                }
            }
        }
        return dp[0][1][k];
    }
};