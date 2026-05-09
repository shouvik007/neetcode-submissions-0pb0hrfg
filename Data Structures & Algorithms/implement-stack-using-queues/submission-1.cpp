class MyStack {
public:
    struct Node {
        int val ;
        shared_ptr<Node> next;
        Node(int v, shared_ptr<Node> n) : val(v), next(n) {}};
    shared_ptr<Node>q;
    MyStack() {
        q=nullptr;
    }
    
    void push(int x) {
        q = make_shared<Node>(x,q);
    }
    
    int pop() {
        if(q==nullptr){
            return -1;
        }
        int x = q->val;
        q= q->next;
        return x;
    }
    
    int top() {
        int x  = q->val;
        return x;
    }
    
    bool empty() {
        if(q==nullptr){
            return true;
        }
        return false;
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