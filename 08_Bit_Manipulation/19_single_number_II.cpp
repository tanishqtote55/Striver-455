/*
    Single Number - II
    Problem Statement: Given an array of numbers, where every number appears thrice except for one element. Return the element that only appears once.

    Examples
    Example 1:
    Input:nums = [5, 5, 5, 2, 4, 4, 4]
    
    
    Output:2
    Explanation:All elements in the input array except 2 ie. [5, 4] appear thrice. Only 2 has the frequency of 1. 
                    
    Example 2:
    Input:nums = [8, 8, 8, 7]
    
    
    Output: 7
    Explanation:In the input array, all elements appear thrice except for 7. Only 7 appear once.
*/

                                
#include <iostream>
#include <vector>
using namespace std;

int findSingleNumber(vector<int>& nums) {
    int ans = 0;

    // Iterate through each bit
    // position (from 0 to 31)
    for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
        // Counter to count the number of
        // set bits at the current bit position
        int cnt = 0; 

        // Iterate through each
        // number in the input array
        for (int i = 0; i < nums.size(); i++) {
            // Check if the bit at bitIndex is
            // set in the current number nums[i]
            if (nums[i] & (1 << bitIndex)) {
                // Increment the counter
                // if the bit is set
                cnt++; 
            }
        }

        // If the count of set bits at the current bit 
        // position is not divisible by 3 (i.e., cnt % 3 == 1)
        // Set the corresponding bit in the answer variable ans
        if (cnt % 3 == 1) {
            ans |= (1 << bitIndex);
        }
    }
    // Return the decimal
    // representation of the answer
    return ans; 
}

int main() {
    vector<int> nums = {4, 4, 4, 2, 5, 5, 5};
    cout << "Input Array: ";
    for (auto num: nums){
        cout << num << " ";
    }
    cout << endl;
    cout << "Element that appears only once: " << findSingleNumber(nums) << endl; 
    return 0;
}

                                
                            