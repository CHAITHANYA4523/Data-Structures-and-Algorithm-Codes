class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        
        // Add all intervals ending before newInterval starts
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        // Merge all overlapping intervals to one considering newInterval
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        // Add the union of intervals we got
        ans.push_back(newInterval);
        
        // Add all the rest
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
