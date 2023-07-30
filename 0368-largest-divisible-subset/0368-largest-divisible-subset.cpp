class Solution {
public:
    typedef int ll;
    // ll rec(ll curr,ll pre,vector<ll>&nums,vector<vector<ll>>&dp){
    //     if(curr>=nums.size())return 0;
    //     ll len=0;
    //     len=rec(curr,pre,nums,dp);
    //     if(pre==-1 || nums[curr]% nums[pre]==0){
    //         len=max(len,1+rec(curr+1,pre,nums,dp));
    //     }
    //     return len;
    // }
    //------------------------------------------------------------------------------
    
    //code taken similar to printing LIS using two for loop (longest lis ending at index curr)
    //bus isme condition alag hai
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        vector<ll>dp(n,1);
        vector<ll>hash(n,1);
        
        for(ll curr=0;curr<n;curr++){
            hash[curr]=curr;
            for(ll pre=0;pre<curr;pre++){
                if(nums[curr]%nums[pre]==0 && 1+dp[pre]>dp[curr]){
                    dp[curr]=1+dp[pre];
                    hash[curr]=pre;
                }
            }
        }
        ll last_index=-1,maxi=0;
        for(ll i=0;i<n;i++){
            if(maxi<dp[i]){
                maxi=dp[i];
                last_index=i;
            }
        }
        vector<ll>ans;
        ans.push_back(nums[last_index]);
        while(hash[last_index]!=last_index){
           
            last_index=hash[last_index];
             ans.push_back(nums[last_index]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};