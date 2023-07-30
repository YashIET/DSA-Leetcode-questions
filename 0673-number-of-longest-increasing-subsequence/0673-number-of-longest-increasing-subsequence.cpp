class Solution {
public:
    typedef int ll;
    int findNumberOfLIS(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>dp(n,1),count(n,1);
        ll maxi=0;
        for(ll i=0;i<n;i++){
            for(ll pre=0;pre<i;pre++){
                if(nums[pre]<nums[i] && 1+dp[pre]>dp[i] ){
                    dp[i]=1+dp[pre];
                    count[i]=count[pre];
                }
                else if(nums[pre]<nums[i] && 1+dp[pre]==dp[i] )count[i]+=count[pre];
            }
            maxi=max(maxi,dp[i]);
        }
        
        ll cnt=0;
    
        for(ll i=0;i<n;i++){
            if(dp[i]==maxi)cnt+=count[i];
        }
        return cnt;
    }
};