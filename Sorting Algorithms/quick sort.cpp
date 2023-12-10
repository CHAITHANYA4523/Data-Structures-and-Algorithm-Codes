#include <iostream>
#include <vector>

using namespace std;

int partition(int lb, int ub, vector<int>& a) {
    int i, j, pivot, t;
    j = ub;
    pivot = lb;
    i = pivot + 1;
    // Loop until i is less than j
    while (i < j) {
        // Increment i while elements are less than or equal to pivot
        while (a[i] <= a[pivot])
            i++;
        // Decrement j while elements are greater than pivot
        while (a[j] > a[pivot])
            j--;
        // Swap elements at i and j if i is less than j
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    // Swap pivot and element at j if i is greater than or equal to j
    if (i >= j) {
        t = a[pivot];
        a[pivot] = a[j];
        a[j] = t;
    }
    return j;
}

void qs(int lb, int ub, vector<int>& a) {
    int p;
    if (lb < ub) {
        p = partition(lb, ub, a);
        qs(lb, p - 1, a);
        qs(p + 1, ub, a);
    }
}

int main() {
    int i, n;
    vector<int> a(10);
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter array elements:\n";
    for (i = 0; i < n; i++)
      cin >> a[i];
    qs(0, n - 1, a);
    cout << "After sorting:\n";
    for (i = 0; i < n; i++)
      cout << a[i] << " ";
    return 0;
}


/*
Time Complexity:
Best Case: The best case occurs when the pivot element is always the median of the elements being sorted. This results in each call processing two halves of the array of equal size. This makes the best case time complexity to be O(NlogN).

Average Case: On average, the partition splits the array into two parts of size N/2
 each, leading to an average time complexity of O(NlogN).

Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot leading to an unbalanced partition. If this happens, we get the worst case time complexity of O(N^2).

Space Complexity:
The space complexity of QuickSort is O(N). This is due to the auxiliary space used to perform the recursive calls.
*/