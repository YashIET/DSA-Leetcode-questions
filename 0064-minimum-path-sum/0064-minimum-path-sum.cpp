class Solution {
public:
    typedef int ll;
    // ll ans=INT_MAX;
    ll n,m;
    ll rec(ll i,ll j,vector<vector<ll>>&grid, vector<vector<long long>>&ans){
        if(i>=n || j>=m)return 1e9;
        //check
        if(ans[i][j]!=-1)return ans[i][j];
        if(i==n-1 && j==m-1)return grid[i][j];
        ll down=grid[i][j] + rec(i+1,j,grid,ans);
        ll right=grid[i][j]+ rec(i,j+1,grid,ans);
        
        return ans[i][j]= (long long)min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        vector<vector<long long>>ans(n,vector<long long>(m,-1));
       ll a= rec(0,0,grid,ans);
        return a;
    }
};