#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    // int longestSubarray(vector<int> &nums, int k){
    //     int max_count = 0;
        
    //     for(int i = 0; i < nums.size(); i++){
    //         int sum = 0;
    //         int count = 0;
    //         for(int j = i; j < nums.size(); j++){
    //             sum += nums[j];
    //             count++;
    //             if(sum == k){
    //                 max_count = max(max_count, count);
    //                 break;
    //             }
    //         }
    //     }
    //     return max_count;
    // }

    // Using Hashmap
    int longestSubarray(vector<int> &nums, int k){
        unordered_map<int, int> preSumMap;
        int sum = 0, maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                maxLen = max(maxLen, i + 1);
            }
            int rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()){
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> a = { -1, 1, 1};
    int k = 1;
    Solution sol;
    int len = sol.longestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// Add the current number to sum.
// If sum == k, it means the subarray from the beginning to now adds up to k. Update the answer.
// If sum - k was seen before, then the subarray from the next index after that to now adds up to k.
// Store sum in the map only if it's not already stored, so we keep the earliest index (to get the longest length).

// nums = [1, 2, 3, -2, 5, -3, 2, 1], k = 5

// | i | nums\[i] | sum | sum == k?  | sum - k | sum-k in map?   | length | maxLen | preSumMap                      |
// | - | -------- | --- | ---------  | ------- | -------------   | ------ | ------ | ------------------------------ |
// | 0 | 1        | 1   | ❌         | -4      | ❌             | —      | 0      | {1: 0}                         |
// | 1 | 2        | 3   | ❌         | -2      | ❌             | —      | 0      | {1: 0, 3: 1}                   |
// | 2 | 3        | 6   | ❌         | 1       | ✅ (index 0)   | 2      | 2      | {1: 0, 3: 1, 6: 2}             |
// | 3 | -2       | 4   | ❌         | -1      | ❌             | —      | 2      | {1: 0, 3: 1, 6: 2, 4: 3}       |
// | 4 | 5        | 9   | ❌         | 4       | ✅ (index 3)   | 1      | 2      | {1: 0, 3: 1, 6: 2, 4: 3, 9: 4} |
// | 5 | -3       | 6   | ❌         | 1       | ✅ (index 0)   | 5      | 5      | already has 6, don't update    |
// | 6 | 2        | 8   | ❌         | 3       | ✅ (index 1)   | 5      | 5      | {1:0, 3:1, 6:2, 4:3, 9:4, 8:6} |
// | 7 | 1        | 9   | ❌         | 4       | ✅ (index 3)   | 4      | 5      | already has 9, don't update    |
