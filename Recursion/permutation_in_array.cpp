class Solution {
public:
    void totalPermutations(vector<vector<int>>& ans, vector<int>& nums, int freq[], vector<int>ds){
        //base case
        if(ds.size() == nums.size()){ //permutation ds size is equal to nums
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                totalPermutations(ans, nums, freq, ds);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        totalPermutations(ans, nums, freq, ds);
        return ans;
    }
};

//Approach 2

//Intuition - try to bring every element to a particular index(do this for all indices) so, we are swapping elements in the above dry run 1,2,3 is brought to index 0.
class Solution {
public:
    void totalPermutations(vector<vector<int>>& ans, vector<int>& nums, vector<int> ds, int index){
        //base case
        if(index == nums.size()){ //permutation ds size is equal to nums
            for(int i=0; i<nums.size(); i++) ds.push_back(nums[i]);
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            totalPermutations(ans, nums, ds, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> ds;
        totalPermutations(ans, nums, ds, 0);
        return ans;
    }
};