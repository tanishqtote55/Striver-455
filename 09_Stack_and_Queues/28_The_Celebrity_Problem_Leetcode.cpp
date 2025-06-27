/*
    Celebrity Problem

    A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.

    Note that M[i][i] is always 0.

    Examples:
    Input: M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]

    Output: 1

    Explanation: Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity.

    Input: M = [ [0, 1], [1, 0] ]

    Output: -1

    Explanation: Both persons know each other, so there is no celebrity.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    // Time Complexity: O(N^2) — because you scan the entire N x N matrix.
    // Space Complexity: O(N) — two O(N) arrays used.
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        vector<int> knowMe(n, 0);
        vector<int> IKnow(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(M[i][j] == 1){
                    knowMe[j]++;
                    IKnow[i]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(knowMe[i] == n - 1 && IKnow[i] == 0){
                return i;
            }
        }
        return -1;
    }

    // Time Complexity: O(N)
    // Space Complexity: O(1) (only constant variables used)
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        int a = 0, b = n - 1;

        // Find the potential celebrity
        while (a < b) {
            if (M[a][b] == 1) {
                // a knows b → a cannot be celebrity
                a++;
            } else {
                // a does not know b → b cannot be celebrity
                b--;
            }
        }

        int candidate = a;

        // Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> M1 = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}
    };

    vector<vector<int>> M2 = {
        {0, 1},
        {1, 0}
    };

    cout << "Celebrity in M1: " << sol.celebrity(M1) << endl;  // Expected: 1
    cout << "Celebrity in M2: " << sol.celebrity(M2) << endl;  // Expected: -1

    return 0;
}