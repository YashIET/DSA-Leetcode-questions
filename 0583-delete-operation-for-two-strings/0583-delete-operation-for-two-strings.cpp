class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll j,string &w1,string &w2,vector<vector<ll>>&dp){
        if(i>=w1.size() || j>=w2.size()){
            if(i>=w1.size())return w2.size()-j;
            else return w1.size()-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j]) return dp[i][j]=rec(i+1,j+1,w1,w2,dp);
         
        ll del1=1+rec(i+1,j,w1,w2,dp);
        ll del2=1+rec(i,j+1,w1,w2,dp);
        return dp[i][j]=min(del1,del2);
    }
    int minDistance(string word1, string word2) {
        vector<vector<ll>>dp(word1.size(),vector<ll>(word2.size(),-1));
        return rec(0,0,word1,word2,dp);
    }
};