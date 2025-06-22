/*
    Check if there exists a subsequence with sum K
    Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

    Examples:
    Input : nums = [1, 2, 3, 4, 5] , k = 8

    Output : Yes

    Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

    Input : nums = [4, 3, 9, 2] , k = 10

    Output : No

    Explanation : No subsequence can sum up to 10.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        //your code goes here
        int n = nums.size();
        vector<int> ds;
        return check(0, ds, 0, k, nums, n);
    }
    bool check(int index, vector<int> &ds, int s, int sum, vector<int> arr, int n){
        if(index == n){
            if(s == sum) return true;
            else return false;
        }
        ds.push_back(arr[index]);
        s += arr[index];
        if(check(index + 1, ds, s, sum, arr, n) == true) return true;
        ds.pop_back();
        s -= arr[index];
        if(check(index + 1, ds, s, sum, arr, n) == true) return true;
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    int k = 2;
    bool found = sol.checkSubsequenceSum(nums, k);
    cout << (found ? "True" : "False") << endl;

    return 0;
}