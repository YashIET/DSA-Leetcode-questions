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
        vector<vector<ll>>dp(text1.size()+1,vector<ll>(text2.size()+1,-1));
        ll ans=lcs(0,0,text1,text2,dp);
        return dp[0][0];
    }
};