class Solution {
public:
    typedef int ll;
    int numberOfPoints(vector<vector<int>>& nums) {
        set<ll>st;
        for(auto it:nums){
            for(ll i=it[0];i<=it[1];i++)st.insert(i);
        }
        return st.size();
    }
};