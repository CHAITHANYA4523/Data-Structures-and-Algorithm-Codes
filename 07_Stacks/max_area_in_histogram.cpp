class Solution {
private:
    vector<int> nextSmallerRight(vector<int> &arr, int n){
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            else nse[i] = -1;
            st.push(i);
        }
        return nse;
    }

    vector<int> nextSmallerLeft(vector<int> &arr, int n){
        stack<int> st;
        vector<int> nse(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            else nse[i] = -1;
            st.push(i);
        }
        return nse;
    }

public:

    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector <int> next(n);
        next=nextSmallerRight(heights,n);
        vector<int> prev(n);
        prev=nextSmallerLeft(heights,n);
        int area=INT_MIN;
        for(int i=0; i<n; i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(newArea,area);
        }
        return area;
    }
};


//One pass Solution 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};


/*
Time Complexity: O( N ) + O (N)
Space Complexity: O(N)
*/
