/*
    Minimum number of platforms required for a railway
    Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.

    In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.

    Examples:
    Input : Arrival = [0900, 0940, 0950, 1100, 1500, 1800] , Departure = [0910, 1200, 1120, 1130, 1900, 2000]

    Output : 3

    Explanation : The first , second , fifth number train can use the platform 1.

    The third and sixth train can use the platform 2.

    The fourth train will use platform 3.

    So total we need 3 different platforms for the railway station so that no train is kept waiting.

    Input : Arrival = [0900, 1100, 1235] , Departure = [1000, 1200, 1240]



    Output : 1



    Explanation : All the three trains can use the platform 1.

    So we required only 1 platform.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int maxPlatforms = 1;

        for (int i = 0; i < n; i++) {
            int platformsNeeded = 1;

            for (int j = 0; j < n; j++) {
                if (i != j && arr[i] >= arr[j] && arr[i] <= dep[j]) {
                    platformsNeeded++;
                }
            }

            maxPlatforms = max(maxPlatforms, platformsNeeded);
        }

        return maxPlatforms;
    }

    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms = 1, maxPlatforms = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            } else {
                platforms--;
                j++;
            }

            maxPlatforms = max(maxPlatforms, platforms);
        }

        return maxPlatforms;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep1 = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Platforms required: " << sol.findPlatform(arr1, dep1) << endl; // Output: 3

    vector<int> arr2 = {900, 1100, 1235};
    vector<int> dep2 = {1000, 1200, 1240};
    cout << "Platforms required: " << sol.findPlatform(arr2, dep2) << endl; // Output: 1

    return 0;
}


// | Metric | Value    |
// | ------ | -------- |
// | Time   | `O(n^2)` |
// | Space  | `O(1)`   |


// | Metric | Value                         |
// | ------ | ----------------------------- |
// | Time   | `O(n log n)` (due to sorting) |
// | Space  | `O(1)`                        |
