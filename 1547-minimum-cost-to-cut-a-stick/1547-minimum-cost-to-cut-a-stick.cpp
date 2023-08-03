class Solution {
public:
    typedef int ll;
    ll rec(ll i,ll j,vector<ll>&cuts,vector<vector<ll>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        ll mini=INT_MAX;
        for(ll k=i;k<=j;k++){
            mini=min(mini,rec(i,k-1,cuts,dp)+rec(k+1,j,cuts,dp)+cuts[j+1]-cuts[i-1]);
        }
        return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        ll sizeini=cuts.size();
        cuts.insert(cuts.begin()+0,0);
        cuts.insert(cuts.begin()+sizeini-1,n);
        sort(cuts.begin(),cuts.end());
        vector<vector<ll>>dp(sizeini+3,vector<ll>(sizeini+3,-1));
        return rec(1,sizeini,cuts,dp);
    }
};