class Solution {
public:
    typedef int ll;
    void dfs(ll root,vector<vector<ll>>&conn,vector<ll>&vis){
        vis[root]=1;
        for(ll i=0;i<conn.size();i++){
            if(conn[root][i]==1 && vis[i]==0 && i!=root){
                dfs(i,conn,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<ll>vis(isConnected.size()+1,0);
        ll cnt=0;
        for(ll i=0;i<isConnected.size();i++){
            if(!vis[i]){
                cnt++;
                dfs(i,isConnected,vis);
            }
        }
        return cnt;
    }
};