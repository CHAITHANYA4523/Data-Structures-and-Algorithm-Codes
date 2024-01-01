#include<bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0, maxlen = 0, zero = 0, one = 0;
    while (j < n) {
        if (nums[j] == 0) {
            zero++;
        } else {
            one++;
        }
        if (zero == one) {
            maxlen = max(maxlen, j - i + 1);
        }
        j++;
        while (zero != one) {
            if (nums[i] == 0) {
                zero--;
            } else {
                one--;
            }
            i++;
        }
    }
    return maxlen;
}

int main() {
    vector<int> nums = {0, 1, 0, 1};
    cout << findMaxLength(nums);
    return 0;
}

/*
The time complexity of the sliding window approach is O(n), where n is the length of the input array. This is because each element in the array is visited at most twice, once by the right pointer (j) and (at most) once by the left pointer (i).

The space complexity is O(1), which means it uses constant extra space. This is because only a fixed number of variables are used. The space usage does not increase with the size of the input array. Hence, it’s very space-efficient.
*/