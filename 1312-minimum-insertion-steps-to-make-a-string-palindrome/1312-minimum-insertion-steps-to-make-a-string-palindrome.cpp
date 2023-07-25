class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll j,string &s,vector<vector<ll>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>j)return 0;
        if(i==j)return 0;
        ll ans=1e9;
        if(s[i]==s[j])ans=rec(i+1,j-1,s,dp);
        else ans=min(rec(i,j-1,s,dp),rec(i+1,j,s,dp))+1;
        return dp[i][j]= ans;
    }
    int minInsertions(string s) {
        ll n=(int)s.size();
        vector<vector<ll>>dp(n,vector<ll>(n,-1));
        return rec(0,n-1,s,dp);
    }
};