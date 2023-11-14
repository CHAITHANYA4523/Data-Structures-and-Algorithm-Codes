// Stack class.
class Stack {
private: 
    int top_index;
    int size;
    int *st;
public:
    Stack(int capacity) {
       this->size = capacity;
       st = new int[size];
       top_index = -1; 
    }

    void push(int num) {
        if(isFull()) return;
        top_index++;
        st[top_index] = num;
    }

    int pop() {
       if(isEmpty()) return -1;
       int x = st[top_index];
       top_index--;
       return x;
    }
    
    int top() {
        if(isEmpty()) return -1;
        return st[top_index];
    }
    
    int isEmpty() {
        if(top_index == -1) return 1;
        return 0;
    }
    
    int isFull() {
        if(top_index == size-1) return 1;
         return 0;
    }
    
};
