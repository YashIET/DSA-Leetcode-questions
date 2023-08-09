typedef int ll;
class MyStack {
    //every time of push we push to q2 and then push all x from q1 to q2 the push all q2 to q1
    queue<ll>q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            ll temp=q1.front();
            q2.push(temp);
            q1.pop();
        }
        while(!q2.empty()){
            ll temp=q2.front();
            q1.push(temp);
            q2.pop();
        }
        
    }
    
    int pop() {
        ll temp=q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        ll temp=q1.front();
        // q1.pop();
        return temp;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */