typedef int ll;
class Solution {
public:
    int findMin(vector<int>& nums) {
        ll mini=INT_MAX;
        ll l=0,h=nums.size()-1;
        while(l<=h){
            ll mid=(l+h)/2;
            if(nums[mid]<mini)mini=nums[mid];
            
            //left is sorted
            if(nums[l]<=nums[mid]){
                if(nums[l]<mini)mini=nums[l];
                l=mid+1;
            }
            else h=mid-1;
        }
        return mini;
    }
};