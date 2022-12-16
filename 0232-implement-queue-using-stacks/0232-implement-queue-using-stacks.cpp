class MyQueue {
public:
    stack<int>temp;
    stack<int>main;
    
    MyQueue() {
       main={};
        temp={};
    }
    
    void push(int x) {
        temp.push(x);
    }
    
    int pop() {
         if(main.size()==0){
           while(temp.size()){
               int val = temp.top();
               temp.pop();
               main.push(val);
           } 
        }
        int res = main.top();
        main.pop();
        return res;
    }
    
    int peek() {
        if(main.size()==0){
           while(temp.size()){
               int val = temp.top();
               temp.pop();
               main.push(val);
           } 
        }
        int res = main.top();
        return res;
    }
    
    bool empty() {
       return (!main.size() && !temp.size());
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