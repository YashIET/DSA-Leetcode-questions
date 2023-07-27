class Solution {
public:
    typedef int ll;
    bool rec(ll i,ll j,string &s,string &t,vector<vector<ll>>&dp){
        if(i==s.size() && j==t.size())return true;
        if(i==s.size()){
            ll flag=0;
            for(j;j<t.size();j++){
                if(t[j]!='*')flag=1;
            }
            if(flag)return false;
            return true;
        }
        if(i>=s.size() || j>=t.size())return false;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j] || t[j]=='?')return dp[i][j]= rec(i+1,j+1,s,t,dp);
        if(t[j]=='*')return dp[i][j]= rec(i+1,j+1,s,t,dp) || rec(i+1,j,s,t,dp) || rec(i,j+1,s,t,dp);
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        vector<vector<ll>>dp(s.size()+1,vector<ll>(p.size()+1,-1));
        // cout<<s.size();
        if(s.size()==0){
            ll flag=0;
            for(auto it:p){
                if(it!='*')flag=1;
            }
            if(flag)return false;
            return true;
            
        }
        return rec(0,0,s,p,dp);
    }
};