typedef int ll;
class MyStack {
    //every time of push we push to q2 and then push all x from q1 to q2 the push all q2 to q1
    queue<ll>q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        ll k=0;
        while(k<q1.size()-1){
            ll temp=q1.front();
            q1.push(temp);
            q1.pop();
            k++;
        }
        //using single queue
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