class Solution {
public:
    typedef int ll;
   
    string shortestCommonSupersequence(string s1, string s2) {
        vector<vector<ll>>dp(s1.size()+1,vector<ll>(s2.size()+1,0));
        ll n=s1.size(),m=s2.size();
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";
        ll i=n,j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){ans+=s1[i-1];i--;j--;}
            else if(dp[i-1][j]>dp[i][j-1]){
                    ans+=s1[i-1];
                    i--;
                }
            else {
                    ans+=s2[j-1];
                    j--;
                }
            
        }
        
        while(i>0){
            ans+=s1[i-1];i--;
        }
        while(j>0){
            ans+=s2[j-1];j--;
        }
        reverse(ans.begin(),ans.end());
        cout<<dp[n][m];
        return ans;
    }
};