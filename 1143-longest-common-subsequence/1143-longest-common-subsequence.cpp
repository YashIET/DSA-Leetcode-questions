class Solution {
public:
    typedef int ll;
    int lcs(ll i, ll j ,string &text1, string &text2, vector<vector<ll>>&dp){
        //if both char are same
        if(i>=text1.size() || j>=text2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        ll len=0;
        if(text1[i]==text2[j]){
            len=1+lcs(i+1,j+1,text1,text2,dp);
        }
        else{
            len=lcs(i+1,j,text1,text2,dp);
            len=max(len,lcs(i,j+1,text1,text2,dp));
        }
        return dp[i][j]=len;
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        ll n=text1.size(),m=text2.size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};