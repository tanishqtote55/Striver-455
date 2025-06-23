/*
    90. Subsets II
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:
    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    
    Example 2:
    Input: nums = [0]
    Output: [[],[0]]

    Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    void printF(int index, vector<int> &ds, vector<int> arr, set<vector<int>> &ans, int n){
        if(index == n){
            ans.insert(ds);
            return;
        }
        // take or pick the particular index into the subsequence
        ds.push_back(arr[index]);
        printF(index + 1, ds, arr, ans, n);
        ds.pop_back();
        // not take or not pick the particular index into the subsequence
        printF(index + 1, ds, arr, ans, n);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ds;
        set<vector<int>> ans;
        printF(0, ds, nums, ans, n);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }

    // Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).
    // Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
    void printF(int index, vector<int> &ds, vector<int> arr, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i = index; i < arr.size(); i++){
            if(i != index && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            printF(i + 1, ds, arr, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        printF(0, ds, nums, ans);
        return ans;
    }
};

// Main function to test
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Unique subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}