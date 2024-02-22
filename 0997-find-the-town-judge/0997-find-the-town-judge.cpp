class Solution {
public:
    typedef int ll;
    int findJudge(int n, vector<vector<int>>& trust) {
        //[a,b]-->a trust b
        //judge dont trust anyone so he cant be a
        //everyone trusts judge so b should be related to each other a
        //let us first make array of if this index person trust anyone or not
        vector<ll>v(n+1,0);
        map<ll,ll>m;
        for(auto it:trust){
            ll a=it[0];
            ll b=it[1];
            v[a]=1;
            m[b]++;
        }
        for(ll i=1;i<n+1;i++){
            if(v[i]==0){
                if(m[i]==n-1)return i;
            }
        }
        return -1;
    }
};