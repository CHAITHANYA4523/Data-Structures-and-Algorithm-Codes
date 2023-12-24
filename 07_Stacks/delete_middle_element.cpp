#include <bits/stdc++.h>

// Recursive function to delete the middle element from the stack
void solve(stack<int>& inputStack, int count, int size) {
    // Base case: If we have reached the middle element, pop it and return
    if (count == size / 2) {
        inputStack.pop();
        return;
    }

    // Get the top element of the stack
    int num = inputStack.top();
    inputStack.pop();

    // Recursive call to process the remaining elements
    solve(inputStack, count + 1, size);

    // Push the element back onto the stack after the recursive call
    inputStack.push(num);
}

// Function to delete the middle element from the stack
void deleteMiddle(stack<int>& inputStack, int N) {
    int count = 0; // Initialize a count variable to keep track of the current position
    solve(inputStack, count, N); // Call the recursive function to delete the middle element
}
