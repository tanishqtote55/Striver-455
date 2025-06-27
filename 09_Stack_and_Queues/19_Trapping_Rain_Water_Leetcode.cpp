/*
    42. Trapping Rain Water

    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

    Example 1:

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
    Example 2:

    Input: height = [4,2,0,3,2,5]
    Output: 9

    Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     if (n <= 2) return 0;

    //     vector<int> leftMax(n), rightMax(n);
    //     int water = 0;

    //     // Fill leftMax[]
    //     leftMax[0] = height[0];
    //     for (int i = 1; i < n; ++i) {
    //         leftMax[i] = max(leftMax[i - 1], height[i]);
    //     }

    //     // Fill rightMax[]
    //     rightMax[n - 1] = height[n - 1];
    //     for (int i = n - 2; i >= 0; --i) {
    //         rightMax[i] = max(rightMax[i + 1], height[i]);
    //     }

    //     // Calculate trapped water
    //     for (int i = 0; i < n; ++i) {
    //         water += min(leftMax[i], rightMax[i]) - height[i];
    //     }

    //     return water;
    // }
    
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;  // Not enough bars to trap water

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Process left side
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            } else {
                // Process right side
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Trapped rainwater: " << sol.trap(height) << endl;
    return 0;
}


// Prefix-Suffix
// | Metric | Complexity |
// | ------ | ---------- |
// | Time   | O(n)       |
// | Space  | O(n)       |


// Two Pointer Technique
// | Metric           | Value |
// | ---------------- | ----- |
// | Time Complexity  | O(n)  |
// | Space Complexity | O(1)  |
