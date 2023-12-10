#include <iostream>
#include <vector>
using namespace std;

vector<int> a(30);

void merge(int lb, int mid, int ub) {
    vector<int> b(30); // Temporary array to hold merged elements
    int i = lb; // Pointer for the left half
    int j = mid + 1; // Pointer for the right half
    int k = lb; // Index for merging into b 
    // Compare and merge elements from both halves until either half is exhausted
    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i]; // Copy element from the left half
            i++;
        } else {
            b[k] = a[j]; // Copy element from the right half
            j++;
        }
        k++;
    } 
    // Copy any remaining elements from the left or right half
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }
    // Copy the merged elements back to the original array a
    for (k = lb; k <= ub; k++)
        a[k] = b[k];
}


void partition(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        partition(low, mid);
        partition(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int n, i;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements to sort: ";
    for (i = 0; i < n; i++)
        cin >> a[i];
    partition(0, n - 1);
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

/* 
Time Complexity: The time complexity of Merge Sort for the best case, average case, and worst case is O(NlogN) This is because the algorithm continuously divides the array into two halves until it cannot be divided further (i.e., the array has only one element left which is always sorted). Then, the sorted subarrays are merged back together into one sorted array.

Space Complexity: The space complexity of Merge Sort is O(N). This is due to the need for a temporary array to hold the merged elements during the sorting process.
*/
