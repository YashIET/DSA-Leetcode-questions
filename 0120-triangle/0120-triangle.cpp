class Solution {
public:
    typedef int ll;
    ll n,m;
    ll rec(ll i,ll j,vector<vector<ll>>&tri,vector<vector<ll>>&dp){
        if(i==n || j==m)return 1e9;
        if(i==n-1 || j==m-1)return tri[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        ll bottom=tri[i][j]+ rec(i+1,j,tri,dp);
        ll right=tri[i][j]+rec(i+1,j+1,tri,dp);
        return dp[i][j]=min(bottom,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        m=triangle[n-1].size();
        vector<vector<ll>>dp(n,vector<ll>(m,-1));
        return rec(0,0,triangle,dp);
    }
};