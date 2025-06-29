/*
    347. Top K Frequent Elements
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Example 1:

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]    

    Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.  

    Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Min-heap: pair<frequency, number>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& [num, f] : freq) {
            minHeap.push({f, num});
            if (minHeap.size() > k) {
                minHeap.pop(); // Keep only top k frequent
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

#include <iostream>
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> res = sol.topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
}
