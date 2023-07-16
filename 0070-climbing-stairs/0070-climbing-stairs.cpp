class Solution {
public:
    typedef int ll;
   
    int climbStairs(int n) {
        
        // ll arr[n+1]={0};
        vector<ll>arr(n+1,0);
        arr[0]=1,arr[1]=1;
        for(ll i=2;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};