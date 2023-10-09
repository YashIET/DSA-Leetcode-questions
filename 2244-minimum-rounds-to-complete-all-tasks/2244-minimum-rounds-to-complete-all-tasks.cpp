typedef int ll;
class Solution {
public:
    ll rec(ll i,vector<ll>&task,vector<ll>&dp){
        if(i==task.size())return 0;
        if(i>=task.size()-1 ) return 1e9;
        if(dp[i]!=-1)return dp[i];
        //either take 2 or 3
        ll ans=1e9;
        if(task[i]==task[i+1])ans=min(ans,1+rec(i+2,task,dp));
        if(i+2<task.size()){
            if(task[i]==task[i+1] && task[i]==task[i+2])ans=min(ans,1+rec(i+3,task,dp));
        }
        return dp[i]= ans;
    }
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        vector<ll>dp(tasks.size()+1,-1);
        ll ans=rec(0,tasks,dp);
        return ans==1e9 ? -1: ans;
    }
};