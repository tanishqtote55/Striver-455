/*
    Find the repeating and missing number
    Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.

    Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

    Examples:
    Input: nums = [3, 5, 4, 1, 1]

    Output: [1, 2]

    Explanation: 1 appears two times in the array and 2 is missing from nums

    Input: nums = [1, 2, 3, 6, 7, 5, 7]

    Output: [7, 4]

    Explanation: 7 appears two times in the array and 4 is missing from nums.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Brute Force Approach
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size(); // size of the array
        int repeating = -1, missing = -1;

        //Find the repeating and missing number:
        for (int i = 1; i <= n; i++) {
            //Count the occurrences:
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) cnt++;
            }

            if (cnt == 2) repeating = i;
            else if (cnt == 0) missing = i;

            if (repeating != -1 && missing != -1)
                break;
        }
        return {repeating, missing};
    }

    // My approach quite similar to better 
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        vector<int> ans(2);
        unordered_map<int, int> freq;
        int n = nums.size();

        int sum = 0;
        int repeat = -1;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            sum += nums[i];
            if(freq[nums[i]] == 2) {
                repeat = nums[i];
            }
        }
        
        int total = n * (n + 1) / 2;
        int missing = total - (sum - repeat);
        
        ans[0] = repeat;
        ans[1] = missing;
        
        return ans;
    }

    // Better Approach using Hashmap
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        vector<int> ans(2);
        unordered_map<int, int> freq;
        int n = nums.size();

        int repeating = -1, missing = -1;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if (freq[i] == 2) { 
                repeating = i;
            }
            else if (freq[i] == 0) { 
                missing = i;
            }
        }
        
        ans[0] = repeating;
        ans[1] = missing;
        return ans;
    }

    // Optimal Approach Using Math
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        long long n = nums.size();

        // Calculate the expected sum and sum of squares
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        // Calculate actual sum and sum of squares
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }
    
        // Difference in sum
        long long val1 = S - SN; // X - Y
        
        // Difference in sum of squares
        long long val2 = S2 - S2N; // X^2 - Y^2
        
        // X^2 - Y^2 = (X + Y) * (X - Y) 
        // So we can find X + Y first:
        long long val2_div_val1 = val2 / val1; // X + Y
        
        // Now we solve:
        // X = [(X + Y) + (X - Y)] / 2
        // Y = X - (X - Y)

        long long X = (val2_div_val1 + val1) / 2;
        long long Y = X - val1;

        return {(int)X, (int)Y};
    }

    // Optimal Approach: Using XOR
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();

        int xr = 0; // Will store X ^ Y (repeating ^ missing)

        for(int i = 0; i < n; i++) {
            xr ^= nums[i];  // XOR with array elements
            xr ^= (i + 1); // XOR with 1..n
        }
    
        // Get rightmost set bit in xr
        int setbit = xr & (-xr);
    
    // If we check the last bit:
    // Numbers with last bit 1:
    // From array: 1, 3, 3, 5
    // From 1-5: 1, 3, 5
    // Numbers with last bit 0:
    // From array: 4
    // From 1-5: 2, 4

        int group1 = 0, group2 = 0;
        for(int i = 0; i < n; i++) {
            if (nums[i] & setbit) 
                group1 ^= nums[i];
            else
                group2 ^= nums[i];
        }

    // Then we combine:
    // array (1^3^3^5) is 4
    // 1-5 (1^3^5) is 7
    // So we do:
    // 4 ^ 7 = 3 — that's a candidate
    
        for(int i = 1; i <= n; i++) {
            if (i & setbit) 
                group1 ^= i;
            else
                group2 ^= i;
        }
    
    // ➥ Group 2 (with last bit 0):
    // From array: 4
    // From 1-5: 2, 4
    // So we compute:
    // 4 (array)
    // 2 ^ 4 (1-5) = 6
    // Then we do:
    // 4 ^ 6 = 2 — that's the missing

        // Now we have two cases; we need to check which is missing and which is repeating
        int freq = 0;
        for(int i = 0; i < n; i++) {
            if (nums[i] == group1) freq++;
        }
    
        if (freq == 2) 
            return {group1, group2}; // first is repeating, then missing
        else 
            return {group2, group1};
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
  
    Solution sol;
    vector<int> result = sol.findMissingRepeatingNumbers(arr);
  
    cout << "Repeating number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}