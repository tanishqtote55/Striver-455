/*
    1423. Maximum Points You Can Obtain from Cards
    There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
    In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
    Your score is the sum of the points of the cards you have taken.
    Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

    Example 1:

    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
    Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

    Example 2:

    Input: cardPoints = [2,2,2], k = 2
    Output: 4
    Explanation: Regardless of which two cards you take, your score will always be 4.
    
    Example 3:

    Input: cardPoints = [9,7,7,9,7,7,9], k = 7
    Output: 55
    Explanation: You have to take all the cards. Your score is the sum of points of all cards.
    
    Constraints:

    1 <= cardPoints.length <= 105
    1 <= cardPoints[i] <= 104
    1 <= k <= cardPoints.length
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        // Start with taking all k cards from the left
        for (int i = 0; i < k; ++i) {
            total += cardPoints[i];
        }

        int maxScore = total;

        // Now shift window: remove one from left end, add one from right end
        for (int i = 0; i < k; ++i) {
            total -= cardPoints[k - 1 - i];         // remove from left
            total += cardPoints[n - 1 - i];         // add from right
            maxScore = max(maxScore, total);
        }

        return maxScore;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    cout << "Test Case 1: ";
    cout << "Max Score = " << sol.maxScore(test1, k1) << "\n"; // Expected: 12

    vector<int> test2 = {2, 2, 2};
    int k2 = 2;
    cout << "Test Case 2: ";
    cout << "Max Score = " << sol.maxScore(test2, k2) << "\n"; // Expected: 4

    vector<int> test3 = {9, 7, 7, 9, 7, 7, 9};
    int k3 = 7;
    cout << "Test Case 3: ";
    cout << "Max Score = " << sol.maxScore(test3, k3) << "\n"; // Expected: 55

    vector<int> test4 = {1, 1000, 1};
    int k4 = 1;
    cout << "Test Case 4: ";
    cout << "Max Score = " << sol.maxScore(test4, k4) << "\n"; // Expected: 1000

    return 0;
}