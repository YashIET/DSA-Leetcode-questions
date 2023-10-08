typedef int ll;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>pre(n,1),suff(n,1);
        for(ll i=0;i<n;i++){
            i==0 ? pre[i]=nums[i] : pre[i]=pre[i-1]*nums[i];
        }
        for(ll i=n-1;i>=0;i--){
            i==n-1 ? suff[i]=nums[i] : suff[i]=suff[i+1]*nums[i];
        }
        vector<ll>ans(n,1);
        for(ll i=0;i<n;i++){
            i==0 ? ans[i]=suff[i+1]: i==n-1 ? ans[i]=pre[i-1] : ans[i]=pre[i-1]*suff[i+1];
        }
        return ans;
    
    }
};