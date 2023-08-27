class Solution {
public:
    typedef int ll;
    bool rec(ll i,ll j,vector<ll>&stones,map<ll,ll>&m,vector<vector<ll>>&dp){
        if(i==stones.size()-1)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        ll pre_jump=stones[i]-stones[j];
        bool ans=false;
        for(ll k=-1;k<=1;k++){
            if(pre_jump+k>0 && m.find(stones[i] + pre_jump+k)!=m.end()){
                ans=ans || rec(m[stones[i] + pre_jump+k],i,stones,m,dp);
            }
        }
        return dp[i][j]= ans;
    }
    bool canCross(vector<int>& stones) {
        map<ll,ll>m;
        vector<vector<ll>>dp(stones.size(),vector<ll>(stones.size(),-1));
        for(ll i=0;i<stones.size();i++){
            m[stones[i]]=i;
        }
        if(stones[1]-stones[0]!=1)return false;
        return rec(1,0,stones,m,dp);
    }
};