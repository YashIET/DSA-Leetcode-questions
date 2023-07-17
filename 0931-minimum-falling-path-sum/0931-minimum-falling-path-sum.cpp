class Solution {
public:
    typedef int ll;
    ll n,m;
    ll rec(ll i,ll j,vector<vector<ll>>&grid,vector<vector<ll>>&dp){
        
        if(i==n-1)return grid[i][j];
        
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        ll left=INT_MAX,right=INT_MAX,bottom=INT_MAX;
        if(j>0)left=grid[i][j]+ rec(i+1,j-1,grid,dp);
        if(j<n-1)right=grid[i][j]+rec(i+1,j+1,grid,dp);
        bottom=grid[i][j]+rec(i+1,j,grid,dp);
        
        return dp[i][j]=min(left,min(right,bottom));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        ll ans=INT_MAX;
        vector<vector<ll>>dp(n,vector<ll>(m,INT_MAX));
        for(ll i=0;i<m;i++){
        
        ans=min(ans,rec(0,i,matrix,dp));
        }
        return ans;
        
    }
};