class Solution {
public:
    typedef int ll;
    ll rec(ll i,vector<ll>&arr,ll k,vector<ll>&dp){
        
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        ll maxi=INT_MIN;
        ll maxNo=-1;
        for(ll ind=0;ind<k;ind++){
            if(i+ind<arr.size()){
                maxNo=max(maxNo,arr[i+ind]);
                ll cost=(ind+1)*maxNo+rec(i+ind+1,arr,k,dp);
                maxi=max(maxi,cost);
            }
        }
        return dp[i]= maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<ll>dp(arr.size(),-1);
        return rec(0,arr,k,dp);   
    }
};