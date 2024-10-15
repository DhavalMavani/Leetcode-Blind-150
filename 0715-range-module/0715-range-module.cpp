class RangeModule {
public:
    map<int, int> ranges;

    void addRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        // erase everything that starts in between left and right
        // update right to be the end of merged range
        while(it != ranges.end() && it->first <= right){
            right = max(it->second, right);
            ++it;
            ranges.erase(prev(it));
        }
        if(it != ranges.begin() && left <= (--it)->second ) it->second = max(it->second, right); // if you can add on to the previous range do it
        else ranges[left] = right; // otherwise add new range
    }
    
    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if(it == ranges.begin()) return false;
        return prev(it)->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = ranges.lower_bound(left);
        int cutEnd = -1;
        // erase every range that starts before right
        // keep track of latest end using cutEnd
        while(it != ranges.end() && it->first < right){
            cutEnd = max(cutEnd, it->second);
            it++;
            ranges.erase(prev(it));
        }
        // if current range overlaps with a range that starts before it
        // update ranges and cutEnd
        if(it != ranges.begin() && left < (--it)->second){
            cutEnd = max(cutEnd, it->second);
            it->second = left;
        }
        // if you left a range hanging then put it in.
        if(right<cutEnd){
            ranges[right] = cutEnd;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */