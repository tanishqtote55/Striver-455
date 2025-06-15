/*
    Length of the longest subarray with zero Sum

    Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// int maxLen(vector<int>& a) {
//     int maxLen = 0;
//     unordered_map<int, int> sumIndexMap;
//     int sum = 0;
//     for (int i = 0; i < a.size(); i++) {
//         sum += a[i];

//         if (sum == 0) {
//             maxLen = i + 1;
//         } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
//             maxLen = max(maxLen, i - sumIndexMap[sum]);
//         } else {
//             sumIndexMap[sum] = i;
//         }
//     }
//     return maxLen;
// }

int maxLen(vector<int>& A){
    int n = A.size();
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}

int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << maxLen(a) << endl;

    return 0;
}
