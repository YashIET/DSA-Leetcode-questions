class Solution {
public:
    typedef int ll;
    int countKConstraintSubstrings(string s, int k) {
        ll n=s.size();
        ll cnt=0;
        ll zero=0,one=0;
        for(ll i=0;i<n;i++){
            zero=0,one=0;
            for(ll j=i;j<n;j++){
                if(s[j]=='0')zero++;
                if(s[j]=='1')one++;
                if(zero<=k || one<=k)cnt++;
            }
        }
        return cnt;
    }
};