/*
    Find row with maximum 1's
    Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.

    If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.


    Examples:
    Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]

    Output: 0

    Explanation: The row with the maximum number of ones is 0 (0 - indexed).

    Input: mat = [ [0, 0], [0, 0] ]

    Output: -1

    Explanation: The matrix does not contain any 1. So, -1 is the answer.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:   
    int rowWithMax1s(vector < vector < int >> & mat) {
        int column = mat[0].size();
        int maxi = 0;
        int ans = -1;
        for(int i = 0; i < mat.size(); i++){
        int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
        if(maxi < sum){
            maxi = sum;
            ans = i;
        }
        }
        return ans;
    }

    int firstOneIndex(const vector<int>& row) {
        int low = 0, high = row.size() - 1;
        int index = row.size(); // If no 1 is found, return size (0 ones)
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1) {
                index = mid;     // potential first 1
                high = mid - 1;  // move left
            } else {
                low = mid + 1;   // move right
            }
        }
        return index;
    }

    int rowWithMax1s(vector<vector<int>>& mat) {
        int maxOnes = 0;
        int ans = -1;
        int cols = mat[0].size();

        for (int i = 0; i < mat.size(); ++i) {
            int idx = firstOneIndex(mat[i]);
            int numOnes = cols - idx;
            if (numOnes > maxOnes) {
                maxOnes = numOnes;
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    Solution sol;
    int result = sol.rowWithMax1s(mat);
    cout << "Row with maximum 1s: " << result << endl;

    return 0;
}