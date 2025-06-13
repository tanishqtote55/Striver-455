/*
    128. Longest Consecutive Sequence
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.

    Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
    Example 3:

    Input: nums = [1,0,1,2]
    Output: 3
    
    Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 0) return 0;
    //     int longest = 1;
    //     unordered_set<int> st;
    //     for (int i = 0; i < n; i++) {
    //         st.insert(nums[i]);
    //     }
    //     for (auto it : st) {
    //         //if 'it' is a starting number:
    //         if (st.find(it - 1) == st.end()) {
    //             //find consecutive numbers:
    //             int cnt = 1;
    //             int x = it;
    //             while (st.find(x + 1) != st.end()) {
    //                 x = x + 1;
    //                 cnt = cnt + 1;
    //             }
    //             longest = max(longest, cnt);
    //         }
    //     }
    //     return longest;
    // }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] - 1 == lastSmaller){
                cnt += 1;
                lastSmaller = nums[i];
            } else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution s;
    cout << "Longest consecutive sequence length is: " << s.longestConsecutive(nums) << endl;

    return 0;
}