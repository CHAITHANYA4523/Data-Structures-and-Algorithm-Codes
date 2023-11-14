
//using the concept of next greater element
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;       // Create a stack to store indices of temperatures.
        int n = temperatures.size(); // Get the size of the temperatures vector.
        vector<int> ans;     // Create a vector to store the result.

        for (int i = n - 1; i >= 0; i--) {
            int count = 0;  // Initialize count for the current temperature.

            // Check if the stack is empty.
            if (st.empty()) {
                ans.push_back(0); // No greater temperature to the right.
            } else if (temperatures[i] >= temperatures[st.top()]) {
                // The current temperature is greater than or equal to the temperature at the top of the stack.
                // Pop temperatures from the stack until a greater temperature is found.
                while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                    st.pop();
                }

                // Calculate the distance by subtracting the current index from the index at the top of the stack.
                if (!st.empty()) {
                    count = st.top() - i;
                }
                ans.push_back(count); // Push the calculated distance into the result vector.
            } else {
                // The current temperature is less than the temperature at the top of the stack.
                // In this case, the distance is equal to the difference in indices.
                count = st.top() - i;
                ans.push_back(count); // Push the calculated distance into the result vector.
            }

            st.push(i); // Push the current index onto the stack.
        }

        // Reverse the result vector to get the correct order.
        reverse(ans.begin(), ans.end());

        return ans; // Return the result vector containing distances to the next greater temperature to the right.
    }
};
