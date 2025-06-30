/*
    135. Candy
    There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

    You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
    Return the minimum number of candies you need to have to distribute the candies to the children.

    Example 1:

    Input: ratings = [1,0,2]
    Output: 5
    Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
    Example 2:

    Input: ratings = [1,2,2]
    Output: 4
    Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    The third child gets 1 candy because it satisfies the above two conditions.

    Constraints:

    n == ratings.length
    1 <= n <= 2 * 104
    0 <= ratings[i] <= 2 * 104
*/

#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Step 1: give each child 1 candy

        // Step 2: left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: sum total candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }

        return total;
    }

//     | Metric | Value |
//     | ------ | ----- |
//     | Time   | O(n)  |
//     | Space  | O(1)  |

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int sum = 1;  // start with 1 for the first child
        int up = 0, down = 0;
        int i = 1;
        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                sum += 1;
                i++;
                continue;
            }
            up = 1;
            while(i < n && ratings[i] > ratings[i - 1]){
                up += 1;
                sum += up;
                i++;
            }
            down = 1;
            while(i < n && ratings[i] < ratings[i - 1]){
                sum += down;
                down++;
                i++;
            }
            if(down > up) sum += down - up; 
        }
        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> ratings1 = {1, 0, 2};
    cout << "Minimum candies for [1,0,2]: " << sol.candy(ratings1) << endl; // Output: 5

    vector<int> ratings2 = {1, 2, 2};
    cout << "Minimum candies for [1,2,2]: " << sol.candy(ratings2) << endl; // Output: 4

    vector<int> ratings3 = {1, 3, 2, 2, 1};
    cout << "Minimum candies for [1,3,2,2,1]: " << sol.candy(ratings3) << endl; // Output: 7

    return 0;
}


// | Metric | Value                                 |
// | ------ | ------------------------------------- |
// | Time   | O(n)                                  |
// | Space  | O(n)        (can be O(1) with tricks) |
