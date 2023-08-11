class StockSpanner {
public:
    typedef int ll;
    //store next greater to left:-->{nge,index};
    // vector<ll>v,temp;
    ll i=-1;
    stack<pair<ll,ll>>st;
    StockSpanner() {
        // v.push_back({0,0});
    }
    
    int next(int price) {
        i++;
        ll ans;
        // temp.push_back(price);
       while(!st.empty() && st.top().first<=price){
           st.pop();
       }
        if(!st.empty()){
            // v.push_back(st.top().second);
            ans=i-st.top().second;
        }
        else{
            // v.push_back(-1);
            ans=i+1;
        }
        st.push({price,i});
        //i-v[i] is the ans
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */