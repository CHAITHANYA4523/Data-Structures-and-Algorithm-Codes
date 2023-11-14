class Solution {
public:
    void uniqueCombinations(vector<vector<int>>& ans, vector<int> ds, vector<int>& candidates, int target, int index){
        if(index == candidates.size()){
            if(target == 0)ans.push_back(ds);
            return ;
        }
        //pick an element
        if(candidates[index] <= target){
            ds.push_back(candidates[index]);
            uniqueCombinations(ans, ds, candidates, target-candidates[index], index);
            ds.pop_back(); // remove element from data structure
        }
        //not pick condition so target remains same
        uniqueCombinations(ans, ds, candidates, target, index+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        uniqueCombinations(ans, ds, candidates, target, 0);
        return ans;
    }
};

//combination sum II

class Solution {
public:
    void uniqueCombinations(vector<vector<int>>& ans, vector<int> ds, vector<int>& arr, int target, int index){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<arr.size(); i++){
            //i > index to check if we are picking the element for the first time in next iteration (our goal is to not pick the same element in one iteration)
            if(i > index && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            uniqueCombinations(ans, ds, arr, target-arr[i], i+1);
            ds.pop_back(); //remove the top element when we backtrack
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        uniqueCombinations(ans, ds, candidates, target, 0);
        return ans;
    }
};

//Time Complexity - 2^n * k where k is the for time taken to store data structure in answer  and 2^n is for pick not pick options (two choices) of each element

//Space complexity - k*x where x is the number of combinations of subsequences and k is the size of the answer.