class Solution {
private: 
    bool check(vector<int>& arr, int curr, vector<bool> &vis){
        if(curr < 0 || curr >= arr.size() || vis[curr]) return false;
        if(arr[curr] == 0){
            return true;
        }
        //mark current cell visited
        vis[curr] = true; 
        return check(arr, curr+arr[curr], vis) || check(arr, curr-arr[curr], vis);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return check(arr, start, vis);
    }
};


/*
Time complexity: 
O(N) - where N is the number of elements in the array arr. This is because in the worst-case scenario, we might visit every cell of the array once.

Space complexity: 
O(N) - We are using a 2D vector vis of size N×1 to keep track of visited cells.
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (arr[curr] == 0) // We reached the target
                return true;

            // Move to the left
            int left = curr - arr[curr];
            if (left >= 0 && !visited[left]) {
                q.push(left);
                visited[left] = true;
            }

            // Move to the right
            int right = curr + arr[curr];
            if (right < n && !visited[right]) {
                q.push(right);
                visited[right] = true;
            }
        }

        return false; // We couldn't reach the target
    }
};
