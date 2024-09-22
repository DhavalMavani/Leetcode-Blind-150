class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    
    void addNum(int num) {
        int s1=maxHeap.size(), s2=minHeap.size();
        if(!s1){
            maxHeap.emplace(num);
            return;
        }
        if(s1>=s2){
            if(maxHeap.top()>num ){
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
                maxHeap.emplace(num);
            }
            else minHeap.emplace(num);
        }
        else{
            if(num>minHeap.top() ){
                maxHeap.emplace(minHeap.top());
                minHeap.pop();
                minHeap.emplace(num);
            }
            else maxHeap.emplace(num);
        }
    }
    
    double findMedian() {
        int s1=maxHeap.size(), s2=minHeap.size();
        if(s1==s2) return (double(maxHeap.top())+minHeap.top())/2;
        else if(s1>s2) return maxHeap.top();
        else return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */