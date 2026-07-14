class Solution
{
public:
    int minMeetingRooms(vector<Interval>& intervals)
    {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b)
             {
                 return a.start < b.start;
             });

        map<int, int> count;

        int rooms = 0;

        for (auto &x : intervals)
        {
            // Reuse the room with the earliest ending meeting
            if (!count.empty() && count.begin()->first <= x.start)
            {
                count.begin()->second--;

                if (count.begin()->second == 0)
                    count.erase(count.begin());
            }
            else
            {
                rooms++;
            }

            count[x.end]++;
        }

        return rooms;
    }
};