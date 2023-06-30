class Solution {
public:
    typedef int ll;
    ll ans=INT_MAX;
    ll n,m;
    ll rec(ll row,ll col,vector<vector<int>>& grid,vector<vector<ll>>&dp){
        if(row==n-1 && col==m-1){
            return dp[row][col]= grid[row][col];
        }
        if(row==n || col==m){
            return dp[row][col]= 100000000;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        
        //go bottom after check
        ll bot=INT_MAX;
        if(row<n-1)
        bot=min(bot,grid[row][col]+ rec(row+1,col,grid,dp));
        //go right
        if(col<m-1)
        bot=min(bot,grid[row][col] +rec(row,col+1,grid,dp));
        return dp[row][col]=bot;
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1));
        rec(0,0,grid,dp);
        return dp[0][0];
    }
};