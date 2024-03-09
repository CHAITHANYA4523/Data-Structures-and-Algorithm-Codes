#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int target) {
    unordered_map<int, int> m;
    int count = 0;
    for (int num : arr) {
        if (m.count(num - target)) {
            count += m[num - target];
        }
        m[num]++;
    }
    return count;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int target = 2;
    cout << "Count of pairs: " << countPairs(arr, target) << endl;
    return 0;
}
