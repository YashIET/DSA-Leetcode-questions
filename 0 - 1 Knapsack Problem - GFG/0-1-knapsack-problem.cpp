//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    typedef int ll;
    //Function to return max value that can be put in knapsack of capacity W.
    //pick or non pick with restriction of weight
    int rec(ll i, ll wei_pick, ll tot_wei, int wt[], int val[], ll n, vector<vector<ll>>&dp){
        if(i>=n)return 0;
        if(dp[i][wei_pick]!=-1)return dp[i][wei_pick];
        ll profit=0;
        //not pick
        profit = rec(i+1,wei_pick,tot_wei,wt,val,n,dp);
        //pick
        if(wei_pick+wt[i]<=tot_wei)
        profit=max(profit,val[i]+ rec(i+1,wei_pick+wt[i], tot_wei, wt,val,n,dp));
        
        return dp[i][wei_pick]= profit;
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<ll>>dp(n+1,vector<ll>(W+1,-1));
       ll ans = rec(0,0,W,wt,val,n,dp);
       return dp[0][0];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends