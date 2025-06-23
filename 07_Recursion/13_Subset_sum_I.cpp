/*
    Subsets I
    Given an array nums of n integers.Return sum of all subsets of the array nums.
    Output can be printed in any order.

    Examples:
    Input : nums = [2, 3]
    Output : [0, 2, 3, 5]
    Explanation :
    When no elements is taken then Sum = 0.
    When only 2 is taken then Sum = 2.
    When only 3 is taken then Sum = 3.
    When element 2 and 3 are taken then sum = 2+3 = 5.

    Input : nums = [5, 2, 1]
    Output : [0, 1, 2, 3, 5, 6, 7, 8]
    Explanation :
    When no elements is taken then Sum = 0.
    When only 5 is taken then Sum = 5.
    When only 2 is taken then Sum = 2.
    When only 1 is taken then Sum = 1.
    When element 2 and 1 are taken then sum = 2+1 = 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int> &sums, vector<int> &nums, int n, int sum) {
        if (index == n) {
            sums.push_back(sum);
            return;
        }
        // Pick the element
        backtrack(index + 1, sums, nums, n, sum + nums[index]);
        // Do not pick the element
        backtrack(index + 1, sums, nums, n, sum);
    }

    vector<int> subsetSums(vector<int>& nums) {
        vector<int> sums;
        int n = nums.size();  // ✅ Use size() instead of length()
        backtrack(0, sums, nums, n, 0);
        sort(sums.begin(), sums.end());
        return sums;
    }
};

// Main function to test
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<int> result = sol.subsetSums(nums);

    for (int sum : result)
        cout << sum << " ";
    cout << endl;

    return 0;
}


/*
    Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
    Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
*/