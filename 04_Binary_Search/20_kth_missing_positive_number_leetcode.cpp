/*
    1539. Kth Missing Positive Number
    Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

    Return the kth positive integer that is missing from this array.

    Example 1:

    Input: arr = [2,3,4,7,11], k = 5
    Output: 9
    Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
    Example 2:

    Input: arr = [1,2,3,4], k = 2
    Output: 6
    Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6. 

    Constraints:

    1 <= arr.length <= 1000
    1 <= arr[i] <= 1000
    1 <= k <= 1000
    arr[i] < arr[j] for 1 <= i < j <= arr.length
    
    Follow up:

    Could you solve this problem in less than O(n) complexity?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0; // count of missing numbers
        int i = 1;     // current number to check
        int index = 0; // pointer to the array

        while (true) {
            if (index < arr.size() && arr[index] == i) {
                index++; // i exists in array, move array pointer
            } else {
                count++; // i is missing
                if (count == k) return i;
            }
            i++; // move to next number
        }
    }

    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) k++; //shifting k
            else break;
        }
        return k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        // Binary search to find the least index such that
        // number of missing numbers before it is >= k
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Number of missing numbers until arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // After binary search, left is the number of elements in arr
        // before the kth missing number
        return left + k;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {4, 7, 9, 10};
    int k = 4;
    int ans = sol.findKthPositive(vec, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}