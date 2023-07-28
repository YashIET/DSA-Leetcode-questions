class Solution {
public:
    typedef int ll;
    
    int maxProfit(vector<int>& prices) {
        ll n=prices.size();
        vector<ll>ahead(2),curr(2);
        ahead[0]=0,ahead[1]=0;
        for(ll i=n-1;i>=0;i--){
            for(ll buy=0;buy<=1;buy++){
                if(buy){
                    curr[1]=max(-prices[i]+ahead[0],ahead[1]);
                }
                else{
                    curr[0]=max(prices[i]+ahead[1],ahead[0]);
                }
            }
            ahead=curr;
        }
        return ahead[1];
    }
};