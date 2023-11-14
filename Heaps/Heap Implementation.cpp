#include <bits/stdc++.h>
using namespace std;

//1 based indexing heap
//left child = 2*index
//right child = 2*index+1
//parent = index/2

class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
          arr[0] = -1;
          size = 0;
        }

        void insertIntoHeap(int val){
            //inserting value at end 
            size = size+1;
            int index = size;
            arr[index] = val;

            //take the node element to correct position to satisfy min or max heap property
            while(index > 1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void deleteFromHeap(){
          if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
          }
          //step 1: put the last element at first index
          arr[1] = arr[size];
          size--;
          //step 2: take the root node to correct position
          int i = 1;
          while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            //<= is used because of 1 based indexing
            if(leftIndex <= size && arr[i] > arr[leftIndex]){ 
              swap(arr[i], arr[leftIndex]);
              i = leftIndex;
            }
            else if(rightIndex <= size && arr[i] > arr[rightIndex]){
              swap(arr[i], arr[rightIndex]);
              i = rightIndex;
            }
            else return;
          }
        }

        void print(){
            for(int i=1; i<=size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

//heapify algorithm takes O(logn) time complexity beacuse the running time of Heapify depends on the height of the tree ‘h’ (which is equal to O(logn), where n is a number of nodes) 
void heapify(int arr[], int n, int i){
  int largest = i;
  int left = 2*i;
  int right = 2*i+1;
  if(left < n && arr[largest] < arr[left]){
    largest = left;
  }
  if(right < n && arr[largest] < arr[right]){
    largest = right;
  }
  if(largest != i){
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n){
  int size = n;
  // Build a max heap (heapify the entire array)
  for (int i = n / 2; i > 0; i--) {
    heapify(arr, n, i);
  }
  while(size > 1){
    //step1: swap the first and last element
    swap(arr[size], arr[1]);
    size--;
    //step2: heapify the root node
    heapify(arr, size, 1);
  }
}

int main(){
    Heap h;
    h.insertIntoHeap(23);
    h.insertIntoHeap(45);
    h.insertIntoHeap(34);
    h.insertIntoHeap(100);
    h.insertIntoHeap(11);
    h.print();
    h.deleteFromHeap();
    h.print();

   int arr[6] = {-1, 54, 53, 55, 52, 50};
   int n = 5;
  //build heap
   for(int i=n/2; i>0; i--){
     heapify(arr, n, i);
   }
   cout << "printing the array after heapification" << endl;
    for(int i = 1; i<=n; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
   //heapsort 
   heapSort(arr, n);
   cout << "prining sorted array" << endl;
   for(int i = 1; i<=n; i++){
     cout << arr[i] << " ";
   }
    cout << endl;
    return 0;
}