/*
    493. Reverse Pairs
    Given an integer array nums, return the number of reverse pairs in the array.

    A reverse pair is a pair (i, j) where:

    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].
    
    Example 1:

    Input: nums = [1,3,2,3,1]
    Output: 2
    Explanation: The reverse pairs are:
    (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
    (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
    Example 2:

    Input: nums = [2,4,3,5,1]
    Output: 3
    Explanation: The reverse pairs are:
    (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
    (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
    (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

    Constraints:

    1 <= nums.length <= 5 * 104
    -231 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // int reversePairs(vector<int>& nums) {
    //     int n = nums.size();
    //     int count = 0;
    //     for(int i = 0; i < n; i++){
    //         for(int j = i + 1; j < n; j++){
    //             if((long long)nums[i] > 2LL * nums[j]){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }

    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1)); 
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += countPairs(arr, low, mid, high); //Modification
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    int n;
    cin >> n;  // first, enter size of array
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];  // then, enter array elements
    }
    Solution sol;
    int result = sol.reversePairs(arr);
    cout << result << endl;
    return 0;
}

// ✅ We use Divide and Conquer.
// ✅ At each merge step:

// We first count reverse pairs in O(n) by using two pointers.

// Then we merge the two halves in O(n).

// ✅ So total complexity is O(n log n).