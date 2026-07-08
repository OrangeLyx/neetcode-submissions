class MedianFinder {
    private: 
    priority_queue<int> mx_heap;
    priority_queue<int,vector<int>,greater<int>> mn_heap;
    // mx_heap=mn_heap+1;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx_heap.size()==mn_heap.size()+1){
            mx_heap.push(num);
            mn_heap.push(mx_heap.top());
            mx_heap.pop();
        }else{
            mn_heap.push(num);
            mx_heap.push(mn_heap.top());
            mn_heap.pop();
        }
    }
    
    double findMedian() {
        if(mx_heap.size()==mn_heap.size()+1) return mx_heap.top();
        else return (mx_heap.top()+mn_heap.top())/2.0;
    }
};
