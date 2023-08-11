typedef int ll;
class MinStack {
public:
    stack<ll>s1;
    stack<pair<ll,ll>>s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || s2.top().first>s1.top()){
            s2.push({val,s1.size()});
        }
    }
    
    void pop() {
        if(s2.top().second==s1.size())s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */