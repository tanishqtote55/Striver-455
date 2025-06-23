/*
    40. Combination Sum II
    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.

    Example 1:

    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output: 
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
    Example 2:

    Input: candidates = [2,5,2,1,2], target = 5
    Output: 
    [
    [1,2,2],
    [5]
    ]
    

    Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public: 
    // void findCombination(int index, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds) {
    //     if(index == arr.size()) {
    //         if(target == 0) {
    //             ans.insert(ds);
    //         }
    //         return;
    //     }

    //     // pick the element if it's not greater than the target
    //     if(arr[index] <= target) {
    //         ds.push_back(arr[index]);
    //         // same index because we can pick the same element again
    //         findCombination(index + 1, target - arr[index], arr, ans, ds);
    //         ds.pop_back(); // backtrack
    //     }

    //     // move to the next index
    //     findCombination(index + 1, target, arr, ans, ds);
    // }
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     sort(candidates.begin(), candidates.end());
    //     set<vector<int>> ans;
    //     vector<int> ds;
    //     findCombination(0, target, candidates, ans, ds);
    //     vector<vector<int>> res(ans.begin(), ans.end());
    //     return res;
    // }

    void findCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); ++i) {
            // Skip duplicates at the same depth
            if (i > index && arr[i] == arr[i - 1]) continue;

            // Stop if element is greater than target
            if (arr[i] > target) break;

            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds); // move to next index
            ds.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to make skipping duplicates easier
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

// Driver
int main() {
    Solution sol;
    vector<int> candidates(100, 1); // 100 times 1
    int target = 30;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    for (const auto& comb : result) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }

    return 0;
}
/*
Time Complexity:O(2^n*k)

Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

Space Complexity:O(k*x)

Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
*/