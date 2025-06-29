/*
    846. Hand of Straights
    Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

    Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

    Example 1:
    Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
    Output: true
    Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
   
    Example 2:
    Input: hand = [1,2,3,4,5], groupSize = 4
    Output: false
    Explanation: Alice's hand can not be rearranged into groups of 4.

    Constraints:

    1 <= hand.length <= 104
    0 <= hand[i] <= 109
    1 <= groupSize <= hand.lengt
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> freq;
        for (int card : hand)
            freq[card]++;

        while (!freq.empty()) {
            int first = freq.begin()->first;

            for (int i = 0; i < groupSize; ++i) {
                int curr = first + i;
                if (freq[curr] == 0)
                    return false;
                freq[curr]--;
                if (freq[curr] == 0)
                    freq.erase(curr);
            }
        }

        return true;
    }
};

// 🔹 Helper to print result
void printResult(vector<int> hand, int groupSize) {
    Solution sol;
    cout << "Input hand = [ ";
    for (int val : hand) cout << val << " ";
    cout << "], groupSize = " << groupSize << endl;

    bool result = sol.isNStraightHand(hand, groupSize);
    cout << "Output: " << (result ? "true" : "false") << endl << endl;
}

int main() {
    printResult({1,2,3,6,2,3,4,7,8}, 3);   // true
    printResult({1,2,3,4,5}, 4);          // false
    printResult({1,1,2,2,3,3}, 3);        // true
    printResult({8,10,12}, 2);           // false
    printResult({1,2,3,4,5,6}, 2);       // true

    return 0;
}