//subset sum I
void func(vector<int>& ans, vector<int> arr, int sum, int N, int i){
    if(i==N){
        ans.push_back(sum);
        return;
    }
    //pick case
    func(ans, arr, sum+arr[i], N, i+1);
    //don't pick case
    func(ans, arr, sum, N, i+1);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    func(ans, arr, 0, N, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

//time complexity - O(2^n)+2^nlog(2^n) every element has two choices pick and not pick along with sorting of ans(ans.size() == arr.size())
//space complexity - 2^n (ans size is 2^n times of arr(subset sum))

// subsetsum 2 

#include <bits/stdc++.h>
class Solution {
public:
    void uniqueSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int index){
            ans.push_back(ds);
        for(int i=index; i<nums.size(); i++){
            //skip when we get two consecutive elements same when we perform the iteration  for inserting 1st element, or 2nd element etc for the same level of recursion
            if(i != index && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            uniqueSubsets(nums, ans, ds, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        uniqueSubsets(nums, ans, ds, 0);
        return ans;
    }
};