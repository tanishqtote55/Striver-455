/*
    152. Maximum Product Subarray

    Given an integer array nums, find a subarray that has the largest product, and return the product.

    The test cases are generated so that the answer will fit in a 32-bit integer.    

    Example 1:

    Input: nums = [2,3,-2,4]
    Output: 6
    Explanation: [2,3] has the largest product 6.
    Example 2:

    Input: nums = [-2,0,-1]
    Output: 0
    Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
    
    Constraints:

    1 <= nums.length <= 2 * 104
    -10 <= nums[i] <= 10
    The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int maxproduct = nums[0];
    //     for(int i = 0; i < n; i++){
    //         int product = nums[i];
    //         for(int j = i + 1; j < n; j++){
    //             maxproduct = max(maxproduct, product);
    //             product *= nums[j];
    //         }
    //         maxproduct = max(maxproduct, product);
    //     }
    //     return maxproduct;
    // }

    // int maxProduct(vector<int>& nums) {
    //     int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    //     for(int i=1;i<nums.size();i++) {
    //         int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
    //         prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
    //         prod1 = temp;
            
    //         result = max(result,prod1);
    //     }

    //     return result;
    // }

    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size();
    
    //     int pre = 1, suff = 1;
    //     int ans = INT_MIN;
    
    //     for (int i = 0; i < n; i++) {
    //         if (pre == 0) pre = 1;
    //         if (suff == 0) suff = 1;
    
    //         pre *= nums[i];
    //         suff *= nums[n - i - 1];
            
    //         ans = max(ans, max(pre, suff)); 
    //     }
    //     return ans;
    // }
    
    // Kadane's Algo
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return maxi;
    }
};
    

int main() {
    vector<int> nums = {2, 3, -2, 4};

    Solution sol;
    cout << "The maximum product subarray is: " << sol.maxProduct(nums) << endl;

    return 0;
}