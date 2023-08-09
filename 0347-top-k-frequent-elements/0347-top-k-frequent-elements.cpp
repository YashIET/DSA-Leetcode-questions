class Solution {
public:
    typedef int ll;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<ll,ll>m;
        for(auto it:nums)m[it]++;
        
        vector<vector<ll>>v(nums.size()+1,vector<ll>());
        for(auto it:m){
            ll no=it.first;
            ll fre=it.second;
            v[fre].push_back(no);
        }
        ll ct=0;
        vector<ll>ans;
        for(ll i=nums.size();i>=0;i--){
            vector<ll>temp=v[i];
            for(auto it:temp){
                ans.push_back(it);
                ct++;
                if(ct==k)break;
            }
            if(ct==k)break;
        }
        return ans;
    }
};