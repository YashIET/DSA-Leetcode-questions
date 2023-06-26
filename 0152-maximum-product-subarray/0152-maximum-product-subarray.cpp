class Solution {
public:
    typedef int ll;
    //first method is generate all subarrays in n3 complexity
    //we can optimise that to n2
    //but can we optimise it to n
    //yes,
    //we see that problem is when we have odd no of negatives
    //in such case we either take prefix or suffix multiplications (max of them)
    //hence we just find all prefixes and suuffixes and our answer is maximum of them
    
    //in case of 0 we see that we will never include subarray including 0 in our answer 
    //so whenver our prefix or suufix result into 0 we simply make our prefix or suffix as 0
    int maxProduct(vector<int>& nums) {
        ll maxi = INT_MIN;
        ll pre=1,suff=1;
        for(ll i=0;i<nums.size();i++){
            //check for pre or suff as 0
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            pre*=nums[i];
            suff*=nums[nums.size()-1-i];
            maxi = max(maxi, max(pre,suff));
        }
        return maxi;
    }
};