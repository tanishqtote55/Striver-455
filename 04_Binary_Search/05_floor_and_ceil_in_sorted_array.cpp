/*
    Floor and Ceil in Sorted Array
    Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

    Examples:
    Input : nums =[3, 4, 4, 7, 8, 10], x= 5

    Output: 4 7

    Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

    Input : nums =[3, 4, 4, 7, 8, 10], x= 8

    Output: 8 8

    Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = -1;
        int ceil = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == x) {
                // If we find exactly x, then both floor and ceil are x
                floor = nums[mid];
                ceil = nums[mid];
                break;
            }
            else if (nums[mid] < x) {
                // If nums[mid] < x, it might be a candidate for floor
                floor = nums[mid];
                left = mid + 1;
            }
            else { 
                // If nums[mid] > x, it might be a candidate for ceil
                ceil = nums[mid];
                right = mid - 1;
            }
        }
        
        return {floor, ceil};
    }
};

int main() {
    int n, x;
    cin >> n >> x; // Number of elements and the value of x
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    vector<int> result = sol.getFloorAndCeil(arr, x);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
