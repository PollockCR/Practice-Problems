// https://leetcode.com/contest/weekly-contest-59/problems/my-calendar-i/

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(pair<int, int> event: myEvents){
            if(event.first > end){
                myEvents.emplace(start, end);
                return true;
            } else if((event.first <= start && start < event.second)
                      || (start < event.second && event.second < end)
                      || (start <= event.first && event.first < end)
                      || (event.first < end && end < event.second)){
                return false;
            }
        }
        myEvents.emplace(start, end);
        return true;
    }

private:
    map<int, int> myEvents;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
