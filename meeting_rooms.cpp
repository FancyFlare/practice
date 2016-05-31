
/*
 * 252. Meeting Rooms
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
 */

    bool canAttendMeetings(vector<Interval>& intervals) {
        //sort according to starting time
        multimap<int, Interval> intervalMap;
        for(int i=0;i<intervals.size();i++){
            intervalMap.insert(pair<int, Interval>(intervals[i].start, intervals[i]));
        }
        multimap<int, Interval>::iterator it = intervalMap.begin();
        while(it != intervalMap.end()){
            int end = (it->second).end;
            it++;
            if(it != intervalMap.end() && end>(it->first)){
                return false;
            }
        }
        return true;
    }
