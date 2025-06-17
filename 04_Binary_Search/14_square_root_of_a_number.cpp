/*
    Find square root of a number
    Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

    Examples:
    Input: n = 36

    Output: 6

    Explanation: 6 is the square root of 36.

    Input: n = 28

    Output: 5

    Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long floorSqrt(long long n)  {
        int ans = 0;
        for(long long i = 0; i < n; i++){
            long long value = i * i;
            if(value <= n){
                ans = i;
            } else {
                break;
            }
        }
        return ans;
    }
    
    long long floorSqrt(long long n)  {
        long long ans = sqrt(n);
        return ans;
    }

    long long floorSqrt(long long n)  {
        long long ans = 0;
        long long left = 1;
        long long right = n;
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if(mid * mid <= n){
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 28;
    int ans = sol.floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
