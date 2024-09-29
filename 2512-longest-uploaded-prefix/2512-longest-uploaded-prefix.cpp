class LUPrefix {
public:
    vector<bool> arr;
    int lastIndex=0;
    LUPrefix(int n) {
        arr.resize(n+1,false);
    }
    
    void upload(int video) {
        arr[video]=true;
        if(video-1==lastIndex){
            int n=arr.size();
            while(video<n && arr[video]) video++;
            lastIndex=video-1;
        }
    }
    
    int longest() {
        return lastIndex;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */