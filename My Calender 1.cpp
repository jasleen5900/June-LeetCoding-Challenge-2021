class MyCalendar {
    map<int, int> cal; // <endTime, statIme>
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
    
        /*lookfor first endTIme that is larger than start time request. 
        First condition checkes if the incoming request should be added 
        to the list of booked slots.*/
        
        map<int,int>::iterator itr = cal.upper_bound(start);
        
        if(itr == cal.end() || end<= itr->second) 
        {
            cal[end]=start;
            return true;
        } 
        
        else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */