class StockSpanner {
public:
    typedef int ll;
    vector<ll>v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        ll cnt=0;
        ll n=v.size();
        for(ll i=n-1;i>=0;i--){
            if(v[i]<=price)cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */