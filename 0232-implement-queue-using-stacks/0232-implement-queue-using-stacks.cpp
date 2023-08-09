typedef int ll;
class MyQueue {
    stack<ll>s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x); 
    }
    
    int pop() {
        while(!s1.empty()){
            ll temp=s1.top();
            s1.pop();
            s2.push(temp);
        }
        ll ans=s2.top();
        s2.pop();
        while(!s2.empty()){
            ll temp=s2.top();
            s2.pop();
            s1.push(temp);
        }
        
        return ans;
    }
    
    int peek() {
         while(!s1.empty()){
            ll temp=s1.top();
            s1.pop();
            s2.push(temp);
        }
        ll ans=s2.top();
        // s2.pop();
        while(!s2.empty()){
            ll temp=s2.top();
            s2.pop();
            s1.push(temp);
        }
        
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */