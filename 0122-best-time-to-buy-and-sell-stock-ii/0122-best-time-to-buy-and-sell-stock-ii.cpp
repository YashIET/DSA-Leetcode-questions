class Solution {
public:
    typedef int ll;
    
    int maxProfit(vector<int>& prices) {
        ll n=prices.size();
        // vector<ll>ahead(2),curr(2);
        ll aheadbuy=0,aheadnotbuy=0,currbuy,currnotbuy;
        aheadnotbuy=0,aheadbuy=0;
        for(ll i=n-1;i>=0;i--){
            //loop not needed
            
               currbuy=max(-prices[i]+aheadnotbuy,aheadbuy);
            
            
               currnotbuy=max(prices[i]+aheadbuy,aheadnotbuy);
            
            
            aheadbuy=currbuy,aheadnotbuy=currnotbuy;
        }
        return aheadbuy;
    }
};