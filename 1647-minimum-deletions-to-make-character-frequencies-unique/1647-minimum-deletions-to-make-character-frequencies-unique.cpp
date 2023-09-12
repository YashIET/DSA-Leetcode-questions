class Solution {
public:
    typedef int ll;
    int minDeletions(string s) {
        map<char,ll>m;
        for(auto it:s){
            m[it]++;
            // cout<<it<<" ";
        }
        vector<ll>v(27);
        for(auto it:m){
            char c=it.first;
            ll fre=it.second;
            v[c-'a']=fre;
        }
        sort(v.begin(),v.end(),greater<>());
        map<ll,ll>m2;
        for(auto it:v){
            m2[it]++;
        }
        ll ans=0;
        for(auto it=m2.rbegin();it!=m2.rend();++it){
            
            ll fre=it->first;
            ll n=it->second;
            if(fre==0)break;
            if(n>1){
                ans+=(n-1);
                // fre[n-1]+=(n-1);
                // if(fre-1!=0)
                m2[fre-1]+=(n-1);
            }
        }
        return ans;
    }
};