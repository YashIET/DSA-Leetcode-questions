class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll j,string &s,string &t,vector<vector<ll>>&dp){
        if(j>=t.size())return 1;
        if(i>=s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        ll nottake=rec(i+1,j,s,t,dp);
        ll take=0;
        if(s[i]==t[j])take+=rec(i+1,j+1,s,t,dp);
        
        return dp[i][j]=nottake+take;
    }
    int numDistinct(string s, string t) {
        vector<vector<ll>>dp(s.size()+1,vector<ll>(t.size()+1,-1));
        return rec(0,0,s,t,dp);
    }
};