class MinStack {
public:
    /** initialize your data structure here. */
    stack<long>s;
    long min=0;
    MinStack() {
        
    }
    
    void push(int x) {
    
      if(!s.size())
      {
          s.push(x);
          min=x;
      }
     
     else if(x<min)
      {
          s.push(x-min+x);
          min=x;
      }
        else
            s.push(x);
    }
    
    void pop() {
        if(s.top() < min)
        {
          min=min-s.top()+min;
        }
        s.pop();
        
    }
    
    int top() {
        
        return s.top() > min ? (int)s.top() : (int)min ;
    }
    
    int getMin() {
      
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */