#include<bits/stdc++.h>
class Solution {
public:
    typedef long long ll;
    ll rec(ll i,ll flag,vector<int>& A, vector<int>& B,vector<vector<ll>>&dp){
        // ll max=0;
        if(i>=A.size())return 0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        if(flag==0){
            return dp[i][flag]= max(A[i]+rec(i+1,0,A,B,dp),A[i]+rec(i+2,1,A,B,dp));
        }
        else{
            return dp[i][flag]= max(B[i]+rec(i+1,1,A,B,dp),B[i]+rec(i+2,0,A,B,dp));
        }
        // return 0;
    }
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        vector<vector<ll>>dp1(A.size()+1,vector<ll>(2,-1)),dp2(A.size()+1,vector<ll>(2,-1));
        ll ans1=rec(0,0,A,B,dp1);
        ll ans2=rec(0,1,A,B,dp2);
        return max(ans1,ans2);
    }
};