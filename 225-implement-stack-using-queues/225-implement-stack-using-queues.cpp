class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.size() == 0) return -1;
        int ret = 0;
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        
        ret = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return ret;
        
    }
    
    int top() {
        if(q1.size() == 0) return -1;
        int ret = 0;
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        
        ret = q1.front();
        q2.push(q1.front());
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return ret;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/*
1 4 5 6

1 4
5
*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */