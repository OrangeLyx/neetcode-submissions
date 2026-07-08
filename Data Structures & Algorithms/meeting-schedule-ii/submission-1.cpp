/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for(const auto & p:intervals){
            if(!pq.empty()&& p.start >= pq.top()){
                pq.pop();
            }
            pq.push(p.end);
        }
        return pq.size();
    }
};
