#define mod 1000000007
class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll k, ll end, vector<vector<ll>>&dp){
        if(k==0 && i==end)return 1;
        if(abs(end-i)>k)return 0;
        if(dp[i+1000][k]!=-1)return dp[i+1000][k]%mod;
        return dp[i+1000][k]= (rec(i-1,k-1,end,dp)%mod+rec(i+1,k-1,end,dp)%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<ll>>dp(2003+abs(endPos)+abs(startPos)+1,vector<ll>(k+1,-1));
        return rec(startPos,k,endPos,dp)%mod;
    }
};