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