class Solution {
public:
    typedef int ll;
    int minOperations(vector<int>& nums, int k) {
        vector<ll>v(33,0);
        ll i=0;
        
        while(i<33){
          for(ll j=0;j<nums.size();j++){
              ll temp=(nums[j]&1);
              nums[j]=nums[j]>>1;
              if(temp!=0)v[i]++;
          }
            i++;
        }
        i=0;
        ll ans=0;
        while(i<33){
            ll temp=(k&1);
            k=k>>1;
            ll temp2=v[i]%2;
            if(temp!=temp2)ans++;
            
            i++;
        }
        return ans;
    }
    
};