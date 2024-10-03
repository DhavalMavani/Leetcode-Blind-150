class MyCalendarThree {
public:
    map<int, int> mp;

    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int booked = 0,ans=0;
        for (auto it = mp.begin(); it != mp.end(); it++) 
        {
            booked += it->second;
            ans=max(ans,booked);            
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */


//  class MyCalendarTwo 
// {
//      // key: time; val: +1 if start, -1 if end
// public:
//     bool book(int start, int end) 
//     {
//     }
// };