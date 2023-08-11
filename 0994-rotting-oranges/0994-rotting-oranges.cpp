class Solution {
public:
    typedef int ll;
    ll bfs(vector<vector<ll>>&grid){
        ll n=grid.size(),m=grid[0].size();
        ll time=0;
        queue<pair<ll,ll>>q;
        for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)if(grid[i][j]==2)q.push({i,j});
        ll dx[]={-1,0,1,0};
        ll dy[]={0,1,0,-1};
        while(!q.empty()){
            ll curr_size=q.size();
            time++;
            for(ll i=0;i<curr_size;i++){
                ll curr_x=q.front().first;
                ll curr_y=q.front().second;
                q.pop();
                for(ll j=0;j<4;j++){
                    ll x=curr_x+dx[j];
                    ll y=curr_y+dy[j];
                    if(x<n && x>=0 && y>=0 && y<m && grid[x][y]==1){
                        
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
        }
        for(auto i:grid){
            for(auto j:i)if(j==1)return -1;
        }
        if(time==0)return time;
        return time-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};