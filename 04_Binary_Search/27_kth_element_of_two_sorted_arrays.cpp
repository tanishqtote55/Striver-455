/*
    Kth element of 2 sorted arrays
    Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

    Examples:
    Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5

    Output: 6

    Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

    Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7

    Output: 256

    Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 7th element of this array is 256.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();

        // Ensure a is the smaller array
        if (n > m) return kthElement(b, a, k);

        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n) ? INT_MAX : a[cut1];
            int r2 = (cut2 == m) ? INT_MAX : b[cut2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return -1; // Should never reach here if k is valid
    }
};

int main() {
    Solution sol;

    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    int result = sol.kthElement(a, b, k);
    cout << "The " << k << "th element of the merged sorted array is: " << result << endl;

    return 0;
}