
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b)
    {
        return a.start<b.start;
    });
        for(int i=0;i<intervals.size();i++)
        {
            if(i+1<intervals.size() && intervals[i].end>intervals[i+1].start)
            {
                return false;
            }
        }
        return true;
    }
};