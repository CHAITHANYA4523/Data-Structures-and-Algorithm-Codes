// Function to find the next greater element to the right of each element in the input array
vector<int> nextGreaterRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize the result array with -1
    stack<int> s; // Create an empty stack

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}


// Function to find the next smaller element to the right of each element in the input array
vector<int> nextSmallerRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize the result array with -1
    stack<int> s; // Create an empty stack

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}


// Function to find the next greater element to the left of each element in the input array
vector<int> nextGreaterLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize the result array with -1
    stack<int> s; // Create an empty stack

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}


// Function to find the next smaller element to the left of each element in the input array
vector<int> nextSmallerLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize the result array with -1
    stack<int> s; // Create an empty stack

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}
