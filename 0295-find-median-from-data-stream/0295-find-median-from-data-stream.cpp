class MedianFinder {
public:
    priority_queue <int> low;
    priority_queue <int,vector<int>,greater<>> high;
    void addNum(int num) {
        
        if(low.empty()){
            low.emplace(num);
            return;
        }
 
        if(low.size()>high.size()){
            if(num>=low.top()){
                high.emplace(num);
            }
            else{
                high.emplace(low.top());
                low.pop();
                low.emplace(num);
            }
        }
        else{
            if(num<=high.top()){
                low.emplace(num);
            }
            else{
                low.emplace(high.top());
                high.pop();
                high.emplace(num);
            }
        }
    }
    
    double findMedian() {
        if(low.size()==high.size()){
            return   double( low.top()+high.top() )/2;
        }
        else if(low.size()>high.size()){
            return low.top();
        }
        else{
            return high.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */