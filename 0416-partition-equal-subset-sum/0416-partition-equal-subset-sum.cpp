class Solution {
public:
    typedef int ll;
    ll total=0;
    ll rec(ll i, ll sum,vector<ll>&nums,vector<vector<ll>>&dp){
        if(i==nums.size()){
            if(sum==total-sum)return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        //include this index element to sum1 || sum2 
        return dp[i][sum]= rec(i+1,sum+nums[i],nums,dp) | rec(i+1,sum,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        for(auto i:nums)total+=i;
        vector<vector<int>>dp(nums.size()+1,vector<ll>(total+1,-1));
        return rec(0,0,nums,dp);
    }
};