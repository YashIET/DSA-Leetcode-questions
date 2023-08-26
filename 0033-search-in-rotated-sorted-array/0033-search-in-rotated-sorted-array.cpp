class Solution {
public:
typedef int ll;
    int search(vector<int>& nums, int target) {
        ll l=0,h=nums.size()-1;
        while(l<=h){
            ll mid=(l+h)>>1;

            if(nums[mid]==target)return mid;

            //left is sorted
           if(nums[mid]>=nums[l])
                if(target>=nums[l] && target<=nums[mid])h=mid-1;
                 else l = mid+1;
           
           else{
                if (target>=nums[mid] && target<=nums[h])l=mid+1;
                else h =mid-1;

           }
        }
        return -1;
    }
};