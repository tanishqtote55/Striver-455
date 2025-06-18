/*
    Matrix Median
    Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.

    Examples:
    Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 

    Output: 5

    Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

    Input: matrix=[ [1, 3, 8], [2, 3, 4], [1, 2, 5] ] 

    Output: 3

    Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 8. So, median = 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMedian(vector<vector<int>>& matrix) {
        vector<int> lst;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                lst.push_back(matrix[i][j]);
            }
        }
        sort(lst.begin(), lst.end());
        return lst[(matrix.size() * matrix[0].size()) / 2];
    }

    int findMedian(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int low = 1, high = 1e9;  // Reasonable search space for values
        int desired = (m * n) / 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Count how many elements <= mid
            int count = 0;
            for (int i = 0; i < m; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count <= desired)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = sol.findMedian(matrix);
    cout << "The median element is: " << ans << endl;
    return 0;
}
                                    
           