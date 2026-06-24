class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int m = intervals.size();
        int start =0;
        int i =0;
        while(i<m && newInterval[0]>intervals[i][1]){
            i++;
        }
        start = i;
        while(i<m && newInterval[1] >= intervals[i][0]) {
             newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        intervals.erase(intervals.begin()+start , intervals.begin() + i);
        intervals.insert(intervals.begin() + start,
                         newInterval);

        return intervals;

    }
};
