class Solution{
private:
    void dfs(Node* &root, vector<int> &temp){
        if(root == NULL) return ;
        dfs(root->left, temp);
        temp.push_back(root->data);
        dfs(root->right, temp);
    }
    
    int mergeAndCount(vector<int> &arr, int l, int m, int r) {
        vector<int> temp(r-l+1);
        int i = l, j = m + 1;
        int count = 0;
        int k = 0;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                count += (m - i + 1); // Increment count when an inversion is found
            }
        }
        while (i <= m) {
            temp[k++] = arr[i++];
        }
        
        while (j <= r) {
            temp[k++] = arr[j++];
        }
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
        return count;
    }
    
    int mergeSortAndCount(vector<int> &arr, int l, int r) {
        int ans = 0;
        if (l < r) {
            int m = (l + r) / 2;
            ans += mergeSortAndCount(arr, l, m);
            ans += mergeSortAndCount(arr, m + 1, r);
            ans += mergeAndCount(arr, l, m, r);
        }
        return ans;
    }
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        vector<int> temp;
        dfs(root, temp);
        int count = 0;
        return mergeSortAndCount(temp, 0, temp.size() - 1);
    }
};