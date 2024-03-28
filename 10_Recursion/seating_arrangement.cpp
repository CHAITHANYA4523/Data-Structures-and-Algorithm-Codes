/*
In a restaurent the manager invited people in groups each group contains atleast 1 and atmost 4persons. each table can accomodate 4 persons at max. all the members of a group should sit at the same table and multiple groups can sit on the same table if their total sum is less than or equal to table size. help the manager to find out the minimum no of tables required in cpp language. test case no of groups = 5, groups[] = {1,2,4,3,3} expected output is 4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTablesRequired(vector<int>& groups, int idx, int remainingSeats) {
    if (idx == groups.size()) return 0;
    int tables = 0;
    if (groups[idx] <= remainingSeats){
        tables = minTablesRequired(groups, idx + 1, remainingSeats - groups[idx]);
    } 
    else{
        tables = 1 + minTablesRequired(groups, idx + 1, 4 - groups[idx]);
    }
    return tables;
}

int main() {
    vector<int> groups = {1, 2, 4, 3, 3};
    sort(groups.begin(), groups.end(), greater<int>());
    int minTables = minTablesRequired(groups, 0, 4);
    cout << "Minimum number of tables required: " << minTables << endl;
    return 0;
}

/*
Time Complexity:
The time complexity of this solution is exponential because at each step, we have two choices: either assign the current group to the current table or start a new table with the current group. This results in a recursive tree with a branching factor of 2. The depth of the recursion tree can be at most equal to the number of groups.
Therefore, the time complexity is O(2^N), where N is the number of groups.
Space Complexity:

The space complexity of the recursive solution depends on the depth of the recursion stack. Since the recursion depth can be at most equal to the number of groups, the space complexity is O(N), where N is the number of groups.
Additionally, sorting the groups array takes O(N log N) space complexity due to the use of sorting algorithm.
*/