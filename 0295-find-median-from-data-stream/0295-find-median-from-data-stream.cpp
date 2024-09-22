class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    
    void addNum(int num) {
        int s1=maxHeap.size(), s2=minHeap.size();

        if(!s1 || maxHeap.top()>num){
            maxHeap.emplace(num);
            s1++;
        }
        else{
            minHeap.emplace(num);
            s2++;
        }

        if(s1>s2+1){
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        }
        else if(s2>s1){
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()) return (double(maxHeap.top())+minHeap.top())/2;
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */