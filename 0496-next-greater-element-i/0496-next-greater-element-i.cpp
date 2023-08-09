class Solution {
public:
    typedef int ll;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<ll>ans(nums2.size(),-1);
        stack<ll>st;
        for(ll i=nums2.size()-1;i>=0;i--){
            if(!st.empty()){
                while(!st.empty() && st.top()<nums2[i])st.pop();
                if(!st.empty())
                ans[i]=st.top();
                st.push(nums2[i]);
            }
            else
            st.push(nums2[i]);
        }
        unordered_map<ll,ll>m;
        for(ll i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
        }
        vector<ll>ans_req;
        for(ll i=0;i<nums1.size();i++){
            ans_req.push_back(ans[m[nums1[i]]]);
        }
        return ans_req;
    }
};