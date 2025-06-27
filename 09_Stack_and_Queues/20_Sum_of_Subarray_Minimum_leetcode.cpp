/*
    907. Sum of Subarray Minimums
    Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

    Example 1:

    Input: arr = [3,1,2,4]
    Output: 17
    Explanation: 
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.
    Example 2:

    Input: arr = [11,81,94,43,3]
    Output: 444

    Constraints:

    1 <= arr.length <= 3 * 104
    1 <= arr[i] <= 3 * 104
*/


#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    // TC O(n^2)
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            int mini = INT_MAX;
            for (int j = i; j < n; ++j) {
                mini = min(mini, arr[j]);  // Keep updating the min
                sum = (sum + mini) % MOD; // Add to total sum
            }
        }

        return (int)sum;
    }

    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        stack<int> st;
        vector<int> prev(n), next(n);

        // Previous less element distances
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // Next less or equal element distances
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Total contribution
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + 1LL * arr[i] * prev[i] * next[i]) % MOD;
        }

        return (int)res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums: " << sol.sumSubarrayMins(arr) << endl;
    return 0;
}
