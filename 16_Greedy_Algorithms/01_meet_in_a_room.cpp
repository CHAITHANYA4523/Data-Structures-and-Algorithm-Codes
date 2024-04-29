class Solution{
    private:
        static bool cmp(pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            pair<int,int> p = {start[i], end[i]};
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);
        int count = 1, ansEnd = v[0].second;
        for(int i=1; i<n; i++){
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
};

//printing the corresponding meeting indices
class Solution{
private:
    static bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        if(a.second.second != b.second.second){
            return a.second.second < b.second.second;
        }
        // If end times are equal, sort based on start times
        return a.second.first < b.second.first;
    }
public:
    vector<int> maxMeetings(int n, vector<int> &start, vector<int> &end){
        vector<int> meetingsIndices;
        vector<pair<int,pair<int,int>>> v;
        for(int i=0; i<n; i++){
            pair<int,int> p = {start[i], end[i]};
            v.push_back({i+1, p});
        }
        sort(v.begin(), v.end(), cmp);
        int ansEnd = v[0].second.second;
        meetingsIndices.push_back(v[0].first);
        for(int i=1; i<n; i++){
            if(v[i].second.first > ansEnd){
                ansEnd = v[i].second.second;
                meetingsIndices.push_back(v[i].first); // Index of the next meeting
            }
        }
        sort(meetingsIndices.begin(), meetingsIndices.end());
        return meetingsIndices;
    }
};