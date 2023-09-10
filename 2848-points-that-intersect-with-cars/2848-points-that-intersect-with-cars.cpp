class Solution {
public:
    typedef int ll;
    int numberOfPoints(vector<vector<int>>& nums) {
       vector<ll>v(102,0);
        for(auto it:nums){
            v[it[0]]++;
            v[it[1]+1]--;
        }
        ll cnt=0;
        for(ll i=1;i<101;i++){
            v[i]+=v[i-1];
            if(v[i]>0)cnt++;
        }
        return cnt;
    }
};