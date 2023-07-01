// class Solution {
// public:
//     typedef int ll;
//     set<vector<ll>>s;
//     ll n;
//     void rec(ll idx,vector<ll>&temp,vector<int>& nums){
//         //base case
//         if(idx>=n){
//             s.insert(temp);
//             return;
//         }
//         //take
//         temp.push_back(nums[idx]);
//         rec(idx+1,temp,nums);
//         //not take
//         temp.pop_back();
//         rec(idx+1,temp,nums);

//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         n=nums.size();
//         vector<ll>temp;
//         sort(nums.begin(),nums.end());
//         rec(0,temp,nums);
//         vector<vector<ll>>ans;

//         for(auto it:s){
//             // vector<ll>temp2;
//             // for(int i=0;i<it.size();i++){
//             //     temp2.push_back(it[i]);
//             // }
//             ans.push_back(it);
//         }
//         return ans;
//     }
// };
class Solution {
public:
      
     void generate(vector<int>&subset,int i,vector<int>&nums,vector<vector<int>>&all)
    {
        if(i==nums.size())
        {
            all.push_back(subset);
            return;
        }
        generate(subset,i+1,nums,all);
        subset.push_back(nums[i]);
         generate(subset,i+1,nums,all);
       subset.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<int>empty;  
        vector<vector<int>>allSubsets;
        generate(empty,0,nums,allSubsets);
        set<vector<int>>st;
        for(int i=0;i<allSubsets.size();i++)
        {
            sort(allSubsets[i].begin(),allSubsets[i].end());
            st.insert(allSubsets[i]);
        }
           vector<vector<int>>all(st.begin(),st.end());
        
        return all;
    }
};
    