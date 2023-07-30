class Solution {
public:
    typedef int ll;
    //similar to lis just conditions differnet
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        ll n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<ll>dp(n,1);
        ll ans=0;
        for(ll curr=0;curr<n;curr++){
            for(ll pre=0;pre<curr;pre++){
                string s1=words[pre];
                string s2=words[curr];
                
                ll cnt=0;
                ll i=0,j=0;
                while(i<s1.size() && j<s2.size()){
                    if(s1[i]==s2[j]){
                        i++;j++;
                    }
                    else {
                        cnt++;
                        j++;
                    }
                }
                if(s1.size()+1==s2.size() && cnt<=1 ){
                    dp[curr]=max(dp[curr],1+dp[pre]);
                }
            }
            ans=max(ans,dp[curr]);
        }
        return ans;
    }
};