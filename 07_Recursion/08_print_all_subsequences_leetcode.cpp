/*
    78. Subsets
    Given an integer array nums of unique elements, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    Example 2:

    Input: nums = [0]
    Output: [[],[0]]
    
    Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(2^n * n) Space Complexity: O(1)
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;  // Total subsets = 2^n
        vector<vector<int>> result;

        for (int mask = 0; mask < total; ++mask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }

        return result;
    }

    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add current subset to result
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            // Include nums[i]
            current.push_back(nums[i]);

            // Recurse with next index
            backtrack(i + 1, nums, current, result);

            // Backtrack (remove last element)
            current.pop_back();
        }
    }

    // Time Complexity: O(2^n) Space Complexity: O(n), recursion stack.
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }

    void printF(int index, vector<int> &ds, vector<int> arr, int n){
        if(index == n){
            for(auto it: ds){
                cout << it << " ";
            }
            cout << endl;
            return;
        }
        // take or pick the particular index into the subsequence
        ds.push_back(arr[index]);
        printF(index + 1, ds, arr, n);
        ds.pop_back();
        // not take or not pick the particular index into the subsequence
        printF(index + 1, ds, arr, n);

    }
};

// Main function to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int n = 3;
    vector<int> ds;
    sol.printF(0, ds, nums, n);
    
    vector<vector<int>> allSubsets = sol.subsets(nums);

    cout << "All subsets:\n";
    for (const auto& subset : allSubsets) {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
