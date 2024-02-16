typedef int ll;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<ll,ll>m;
        for(auto it:arr){
            m[it]++;
        }
        vector<pair<ll,ll>>v;
        for(auto it:m){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        ll ans=v.size();
        for(ll i=0;i<v.size();i++){
            k-=v[i].first;
            if(k>=0){
                ans--;
                continue;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};