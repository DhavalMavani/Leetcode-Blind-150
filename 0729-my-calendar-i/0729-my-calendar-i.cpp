class MyCalendar {
public:
    set<pair<int,int>> st;
    
    bool book(int start, int end) {
        auto it= st.lower_bound({start,-1});

       // overlap with the next interval
       if (it != st.end() && (*it).first<end) return 0;
        
        // overlap with the previous interval
        if (it != st.begin() && (prev(it))->second > start) return 0;

        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */