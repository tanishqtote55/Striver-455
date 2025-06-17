/*
    540. Single Element in a Sorted Array
    You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

    Return the single element that appears only once.

    Your solution must run in O(log n) time and O(1) space.

    Example 1:

    Input: nums = [1,1,2,3,3,4,4,8,8]
    Output: 2
    Example 2:

    Input: nums = [3,3,7,7,10,11,11]
    Output: 10

    Constraints:

    1 <= nums.length <= 105
    0 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }

    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size(); //size of the array.

        //Edge cases:
        if (n == 1) return arr[0];
        if (arr[0] != arr[1]) return arr[0];
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            //if arr[mid] is the single element:
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }

            //we are in the left:
            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                    || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                //eliminate the left half:
                low = mid + 1;
            }
            //we are in the right:
            else {
                //eliminate the right half:
                high = mid - 1;
            }
        }

        // dummy return statement:
        return -1;
    }

    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // We want to check whether we are in the left side or the right side
            if (mid % 2 == 0) { // even index
                if (nums[mid] == nums[mid + 1]) {
                    left = mid + 2;
                } else {
                    right = mid;
                }
            } else { // odd index
                if (nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = sol.singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
