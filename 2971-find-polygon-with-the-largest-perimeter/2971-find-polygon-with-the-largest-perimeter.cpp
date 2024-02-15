typedef long long ll;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // ll sum_max=nums[0]+nums[1],no_max=2,curr_sum=nums[0]+nums[1],curr_no=2;
        // for(ll i=2;i<nums.size();i++){
        //     if(curr_sum>nums[i]){
        //         curr_no++;
        //         curr_sum+=nums[i];
        //         no_max=max(no_max,curr_no);
        //         sum_max=max(sum_max,curr_sum);
        //     }
        //     else{
        //         curr_sum=nums[i]+nums[i+1];
        //         curr_no=2;
        //         i++;i++;
        //     }
        // }
        // if(curr_sum>nums[nums.size()-1]){
        //         curr_no++;
        //         curr_sum+=nums[nums.size()-1];
        //         no_max=max(no_max,curr_no);
        //         sum_max=max(sum_max,curr_sum);
        //     }
        ll ans=0;
        for(ll i=0;i<nums.size()-1;i++){
            ans+=nums[i];
        }
        for(ll i=nums.size()-1;i>=2;i--){
            if(ans>nums[i]){
                return ans+nums[i];
            }
            else{
                ans-=nums[i-1];
            }
        }
        return -1;
    }
};