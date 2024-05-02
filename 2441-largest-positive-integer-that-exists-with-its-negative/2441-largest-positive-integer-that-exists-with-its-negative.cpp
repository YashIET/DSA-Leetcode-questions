class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m.find(-nums[i])!=m.end() && abs(nums[i])>ans)ans=abs(nums[i]);
        }
        return ans;
    }
    
};