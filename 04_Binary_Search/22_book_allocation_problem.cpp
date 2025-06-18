/*
    Book Allocation Problem
    100
    Hint
    Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.

    Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

    Examples:
    Input: nums = [12, 34, 67, 90], m=2

    Output: 113

    Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

    Input: nums = [25, 46, 28, 49, 24], m=4

    Output: 71

    Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Check if allocation is possible under the given maxPages
    bool isPossible(vector<int>& nums, int m, int maxPages) {
        int studentCount = 1;
        int currentPages = 0;

        for (int pages : nums) {
            if (pages > maxPages) return false; // Single book exceeds max limit
            if (currentPages + pages > maxPages) {
                studentCount++;
                currentPages = pages;
            } else {
                currentPages += pages;
            }
        }

        return studentCount <= m;
    }

    // int findPages(vector<int>& nums, int m) {
    //     int n = nums.size();
    //     if (m > n) return -1;

    //     int low = *max_element(nums.begin(), nums.end());
    //     int high = accumulate(nums.begin(), nums.end(), 0);

    //     for (int pages = low; pages <= high; pages++) {
    //         if (isPossible(nums, m, pages)) {
    //             return pages;
    //         }
    //     }

    //     return -1; // Just in case no allocation is possible
    // }
    
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        if (m > n) return -1; // Not enough books
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(nums, m, mid)) {
                ans = mid;
                right = mid - 1; // Try for smaller max
            } else {
                left = mid + 1; // Need bigger max
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    int ans = sol.findPages(arr, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

