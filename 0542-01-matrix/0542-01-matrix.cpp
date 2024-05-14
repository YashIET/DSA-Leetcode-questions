class Solution {
public:
    typedef int ll;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //let us use bfs
        ll n=mat.size();
        ll m=mat[0].size();
        vector<vector<ll>>vis(n,vector<ll>(m,0));
        vector<vector<ll>>dis(n,vector<ll>(m,0));
        queue<pair<pair<ll,ll>,ll>>q;
        for(ll i=0;i<mat.size();i++){
            for(ll j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){q.push({{i,j},0});vis[i][j]=1;}
            }
        }
        ll row[]={-1,0,1,0};
        ll col[]={0,1,0,-1};
        
        while(!q.empty()){
            auto it=q.front();
            ll cx=it.first.first,cy=it.first.second,distance=it.second;
            q.pop();
            dis[cx][cy]=distance;
            
            for(ll i=0;i<4;i++){
                ll nrow=cx+row[i];
                ll ncol=cy+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},distance+1});
                }
            }
        }
        return dis;
    }
};