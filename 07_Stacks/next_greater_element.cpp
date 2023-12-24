// Function to find the next greater element to the right of each element in the input array
vector<int> nextGreaterElement(vector<int>& arr, int n) {
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        result[i] = !s.empty() ? arr[s.top()] : -1;
        s.push(i);
    }

    return result;
}

// Function to find the next smaller element to the right of each element in the input array
vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> s;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        result[i] = !s.empty() ? arr[s.top()] : -1;
        s.push(i);
    }

    return result;
}

// Function to find the next greater element to the left of each element in the input array
vector<int> previousGreaterElement(vector<int>& arr, int n) {
    stack<int> s;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        result[i] = !s.empty() ? arr[s.top()] : -1;
        s.push(i);
    }

    return result;
}

// Function to find the next smaller element to the left of each element in the input array
vector<int> previousSmallerElement(vector<int>& arr, int n) {
    stack<int> s;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        result[i] = !s.empty() ? arr[s.top()] : -1;
        s.push(i);
    }

    return result;
}
