class Solution {
public:
    typedef int ll;
    int countOrders(int n) {
        long long ans=1;ll mod=1e9+7;
        for(ll i=1;i<=n;i++){
            ans=(ans*(i)*(2*i-1))%mod;
        }
        return ans;
    }
};