class Solution {
public:
    typedef int ll;
    bool isPalin(ll i,ll j,string &temp){
        // ll i=0,j=temp.size()-1;
        while(i<j){
            if(temp[i++]!=temp[j--])return false;
            
        }
        return true;
    }
    ll rec(ll i,string &s,vector<ll>&dp){
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        ll mini=INT_MAX;
        // string temp="";
        for(ll ind=i;ind<s.size();ind++){
            // temp+=s[ind];
            
            if(isPalin(i,ind,s)){
                ll count=1+rec(ind+1,s,dp);
                mini=min(mini,count);
            }
            
        }
        return dp[i]= mini;
    }
    //------------------------------------tabulation-------------------------------------
    int minCut(string s) {
        vector<ll>dp(s.size()+1,0);
        ll n=s.size();
        for(ll i=n-1;i>=0;i--){
            ll mini=INT_MAX;
       
        for(ll ind=i;ind<n;ind++){
                   
            if(isPalin(i,ind,s)){
                ll count=1+dp[ind+1];
                mini=min(mini,count);
            }
            
        }
            dp[i]= mini;
        }
        return dp[0]-1;
    }
};