class MyCircularQueue {
public:
    
    int front;
    int rear;
    int size;
    int *arr;
    
    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        arr = new int[k];
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front++;
        }
        rear=(rear+1)%size;
        arr[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1)%size;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if(front == (rear+1)%size){
            return true;
        }
        else{
            return false;
        }
    }
};