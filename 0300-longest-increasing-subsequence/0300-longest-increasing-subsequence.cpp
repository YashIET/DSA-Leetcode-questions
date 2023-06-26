class Solution {
public:
    typedef int ll;
    //take current or not
    //what will be the states
    //current idx and previous idx
//     int rec(ll curr, ll pre, vector<ll>&nums,  vector<vector<ll>>&dp){
//         if(curr==nums.size())return 0;
        
//         //not take current idx
//         if(dp[curr][pre+1]!=-1)return dp[curr][pre+1];
//         ll length = rec(curr+1,pre,nums, dp);
//         //take
//         // first check if curr can be taken or not
//         if(pre==-1 || nums[curr]>nums[pre])
//         length = max(length,1+rec(curr+1, curr,nums, dp));
        
//         return dp[curr][pre+1] =  length;
        
//     }
    int lengthOfLIS(vector<int>& nums) {
        //2nd approach in nlogn time
        //temp.size()also takes some time
        ///hence use another length variable
        vector<ll>temp;
        ll len=1;
        temp.push_back(nums[0]);
        for(ll i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){temp.push_back(nums[i]);len++;}
            else{
                ll idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return len;
        
    }
};