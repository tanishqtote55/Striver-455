/*
    Count subarrays with given xor K
    Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

    Examples:
    Input : nums = [4, 2, 2, 6, 4], k = 6

    Output : 4

    Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

    Input :nums = [5, 6, 7, 8, 9], k = 5

    Output : 2

    Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/




#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size(); //size of the given array.
//     int cnt = 0;

//     // Step 1: Generating subarrays:
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {

//             //step 2:calculate XOR of all
//             // elements:
//             int xorr = 0;
//             for (int K = i; K <= j; K++) {
//                 xorr = xorr ^ a[K];
//             }

//             // step 3:check XOR and count:
//             if (xorr == k) cnt++;
//         }
//     }
//     return cnt;
// }

// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size(); //size of the given array.
//     int cnt = 0;

//     // Step 1: Generating subarrays:
//     for (int i = 0; i < n; i++) {
//         int xorr = 0;
//         for (int j = i; j < n; j++) {

//             //step 2:calculate XOR of all
//             // elements:
//             xorr = xorr ^ a[j];

//             // step 3:check XOR and count:
//             if (xorr == k) cnt++;
//         }
//     }
//     return cnt;
// }

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

