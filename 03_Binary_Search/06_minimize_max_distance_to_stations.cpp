/*
To minimize the maximum distance between adjacent gas stations after adding k new stations, we can use a binary search. The key insight is to find the smallest possible value of the maximum distance d that can be achieved by optimally placing the k additional gas stations.

Approach
Binary Search Initialization:

Define the search range for the maximum distance d. The lower bound left is 0, and the upper bound right is the maximum distance between any two existing adjacent gas stations.
The goal is to find the minimum value of d using binary search within this range.
Binary Search Loop:

Calculate the midpoint mid of the current search range.
Check if it is possible to place k additional gas stations such that the maximum distance between any two adjacent stations is less than or equal to mid.
If it is possible, then mid is a potential solution, and we try for a smaller d by setting right = mid.
If it is not possible, we need a larger d, so we set left = mid.
Feasibility Check (canPlaceStations method):

For each pair of adjacent stations, calculate the distance between them.
Determine how many additional stations are needed to ensure no segment exceeds mid.
Sum up all the required additional stations and check if this sum is within the given k.
Precision Handling:

Continue the binary search until the difference between left and right is very small (e.g., 1e-6), ensuring the result is accurate to two decimal places.
Round the final result to two decimal places.
Complexity
Time complexity: 𝑂(𝑛log⁡(max_distanceprecision))O(nlog(precisionmax_distance​))
The binary search runs in 𝑂(log⁡(max_distanceprecision))O(log(precisionmax_distance​)) iterations.
For each iteration, checking the feasibility involves iterating through the stations array, which takes 𝑂(𝑛)O(n) time.
Space complexity: 𝑂(1)O(1)
Only a few variables are used, independent of the input size.
*/

class Solution{
private:
    double getMaxDistance(vector<int> &stations){
        double dist = 0.0;
        int n =stations.size();
        for(int i=1; i<n; i++){
            dist = max(dist, double(stations[i]-stations[i-1]));   
        }
        return dist;
    }
    
    bool canPlaceStations(vector<int> &stations, int n,
    int k, double mid){
        int requiredStations = 0;
        for(int i=1; i<n; i++){
            double dist = stations[i] - stations[i-1];
            requiredStations += ceil(dist/mid) - 1;
        }
        return requiredStations <= k;
    }
public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double low = 0, high = getMaxDistance(stations);
        int n = stations.size();
        while(high-low > 1e-6){
            double mid = (low + high)/2;
            if(canPlaceStations(stations, n, k, mid)){
                high = mid;
            }
            else {
                low = mid;
            }
        }
        return round(high*100.0)/100.0;
    }
};

/*
To analyze the time and space complexity of the given solution, we need to inspect each part of the code separately.

### Time Complexity

1. getMaxDistance Function:
   - This function iterates through the stations vector once.
   - Time complexity: O(n), where ( n ) is the number of elements in the stations vector.

2. canPlaceStations Function:
   - This function also iterates through the stations vector once, and performs some constant time operations within the loop.
   - The use of ceil is a constant time operation.
   - Time complexity: O(n).

3. findSmallestMaxDist Function:
   - The main while loop continues until high - low is less than ( 1e-6 ). This indicates a binary search approach on the distance.
   - The number of iterations of the while loop is proportional to the logarithm of the range divided by the precision: (O(n log(range /precision))).
     - Here, the range is determined by the initial values of high and low.
     - The precision is ( 1e-6 ).
   - Within each iteration of the while loop, canPlaceStations is called, which has a time complexity of O(n).

Combining these, the time complexity for the findSmallestMaxDist function is:
[O(n log(range /precision))]
Where:
- n is the number of stations.
- The range is the difference between the maximum and minimum possible values for the distance.

### Space Complexity

1. Space complexity for getMaxDistance:
   - Uses a few additional variables, independent of the input size.
   - Space complexity: O(1).

2. Space complexity for canPlaceStations:
   - Uses a few additional variables, independent of the input size.
   - Space complexity: O(1).

3. Space complexity for findSmallestMaxDist:
   - Uses variables for the bounds (low, high), the number of stations, and some temporary variables.
   - Space complexity: O(1).

### Overall Complexity

- Time Complexity: O(n log(range /precision))
- Space Complexity:  O(1)

Thus, the solution is efficient in terms of both time and space, with linearithmic time complexity and constant space complexity.
*/