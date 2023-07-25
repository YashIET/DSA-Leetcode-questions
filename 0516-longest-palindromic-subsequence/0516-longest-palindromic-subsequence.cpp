class Solution {
public:
    typedef int ll;
    
    ll rec(ll i,ll j,string &s1,vector<vector<ll>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>j)return 0;
       
        if(i==j)return 1;
        if(s1[i]==s1[j])return dp[i][j]= 2+rec(i+1,j-1,s1,dp);
        return dp[i][j]= max(rec(i+1,j,s1,dp),rec(i,j-1,s1,dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<ll>>dp(s.size(),vector<ll>(s.size(),-1));
        return rec(0,s.size()-1,s,dp);
    }
};