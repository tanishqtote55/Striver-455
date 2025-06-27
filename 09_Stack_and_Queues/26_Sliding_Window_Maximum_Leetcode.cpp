/*
    239. Sliding Window Maximum

    You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

    Return the max sliding window.

    Example 1:

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
    

    Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // TC O((N-K) * K) SC O(N-K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxi;
        for(int i = 0; i <= nums.size() - k; i++){
            int maxElement = nums[i];
            for(int j = i + 1; j < i + k; j++){
                maxElement = max(maxElement, nums[j]);
            }   
            maxi.push_back(maxElement); 
        }
        return maxi;
    }

    // Time: O(n) Space: O(k) for deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements outside the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Remove smaller elements in k range as they are useless
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current element index
            dq.push_back(i);

            // The first index that forms a valid window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

// Sample main function
int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    vector<int> res = sol.maxSlidingWindow(nums, k);
    cout << "Max in each sliding window: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

