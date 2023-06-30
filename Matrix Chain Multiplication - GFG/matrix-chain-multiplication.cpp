//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    typedef int ll;
    
    ll rec(ll i,ll j,ll arr[],ll n,vector<vector<ll>>&dp){
        if(i==j)return 0;
        ll ans=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(ll k=i;k<j;k++){
            ll no_of_mul=rec(i,k,arr,n,dp)+rec(k+1,j,arr,n,dp)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,no_of_mul);
        }
        return dp[i][j]= ans;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
        ll ans=rec(1,n-1,arr,n,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends