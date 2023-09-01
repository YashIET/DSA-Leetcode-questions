class Solution {
public:
    typedef int ll;
    vector<int> countBits(int n) {
        vector<ll>ans;
        for(ll i=0;i<=n;i++){
          ans.push_back(__builtin_popcount(i));  
        }
        return ans;
    }
};