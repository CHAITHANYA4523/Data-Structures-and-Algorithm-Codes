#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{
    for(int i=0; i<n-1; i++){
        // Assume the current element is the smallest
        int minIndex=i;
        // Iterate over the remaining elements in the array
        for(int j=i+1; j<n; j++){
            // If a smaller element is found, update minIndex
            if(arr[j]<arr[minIndex])
            minIndex=j;
        }
        // Swap the smallest element found with the current element
        swap(arr[minIndex],arr[i]);
    }
}
 
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
      cin >> arr[i];
    selectionSort(arr, n);
    cout << "After sorting:\n";
    for(int i = 0; i < n; i++)
      cout << arr[i] << " ";
    return 0;
}


/*
Time Complexity:
Best Case: The best case occurs when the array is already sorted. This results in a best case time complexity of O(N^2).

Average Case: The average case arises when the elements of the array are in a disordered or random order, without a clear ascending or descending pattern. This leads to an average time complexity of O(N^2).

Worst Case: The worst-case scenario arises when we need to sort an array in ascending order, but the array is initially in descending order. The time complexity of the Selection sort remains constant regardless of the input array’s initial order. At each step, the algorithm identifies the minimum element and places it in its correct position. However, the minimum element cannot be determined until the entire array is traversed. This results in a worst case time complexity of O(N^2).

Space Complexity:
The space complexity of Selection Sort is O(1). This is due to the fact that it does not require any additional memory space apart from a temporary variable used for swapping.
*/      
        
      
    
  

  
  
  
  
  
  
    
    
     
  

         
        
        
    
  

    
    
    
    
    
  