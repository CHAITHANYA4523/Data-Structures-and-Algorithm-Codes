typedef pair<int,int> pii; 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto x:nums) mp[x]++;
        for(auto it = mp.begin(); it != mp.end(); it++){
            minHeap.push(make_pair(it->second, it->first));
            if(minHeap.size() > k) minHeap.pop();
        }
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

//time complexity - O(n * log(k)).
//space complexity - O(n)