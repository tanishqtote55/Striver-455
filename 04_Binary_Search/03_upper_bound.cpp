/*
    Upper Bound
    Given a sorted array of nums and an integer x, write a program to find the upper bound of x. The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than a given key i.e. x.

    If no such index is found, return the size of the array.

    Examples:
    Input : n= 4, nums = [1,2,2,3], x = 2

    Output:3

    Explanation: Index 3 is the smallest index such that arr[3] > x.

    Input : n = 5, nums = [3,5,8,15,19], x = 9

    Output: 3

    Explanation: Index 3 is the smallest index such that arr[3] > x.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // int upperBound(vector<int> &nums, int x){
    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i] > x){
    //             return i;
    //         }
    //     }  
    // }

    int upperBound(vector<int> &nums, int x){
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > x){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.upperBound(nums, x) << '\n';

    return 0;
}