/*
    Fruit Into Baskets
    There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.

    The goal is to gather as much fruit as possible, adhering to the owner's stringent rules:
    1) There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
    2) Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
    3) Once reaching a tree with fruit that cannot fit into any basket, stop.

    Return the maximum number of fruits that can be picked.

    Examples:
    Input : fruits = [1, 2, 1]
    Output : 3
    Explanation : We will start from first tree.
    The first tree produces the fruit of kind '1' and we will put that in the first basket.
    The second tree produces the fruit of kind '2' and we will put that in the second basket.
    The third tree produces the fruit of kind '1' and we have first basket that is already holding fruit of kind '1'. So we will put it in first basket.
    Hence we were able to collect total of 3 fruits.

    Input : fruits = [1, 2, 3, 2, 2]
    Output : 4
    Explanation : we will start from second tree.
    The first basket contains fruits from second , fourth and fifth.
    The second basket will contain fruit from third tree.
    Hence we collected total of 4 fruits.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
  public:
    // int totalFruits(vector<int>& fruits){
    //     //your code goes here
    //     int maxlen = 0;
    //     for (int i = 0; i < fruits.size(); i++) {
    //         set<int> st;
    //         for (int j = i; j < fruits.size(); j++) {
    //             st.insert(fruits[j]);
    //             if (st.size() <= 2)
    //                 maxlen = max(maxlen, j - i + 1);
    //             else
    //                 break;
    //         }
    //     }
    //     return maxlen;
    // }

    int totalFruits(vector<int>& fruits){
        unordered_map<int, int> basket; // fruit -> count
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            // If more than 2 types of fruits, shrink the window
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0)
                    basket.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    int totalFruits(vector<int>& fruits){
        unordered_map<int, int> basket; // fruit -> count
        int left = 0, maxLen = 0, right = 0;

        while (right < fruits.size()) {
            basket[fruits[right]]++;

            // If more than 2 types of fruits, shrink the window
            if(basket.size() > 2){
                basket[fruits[left]]--;
                if(basket[fruits[left]] == 0) basket.erase(fruits[left]);
                left++;
            }
            if(basket.size() <= 2){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};


int main() {
    Solution sol;

    vector<int> fruits1 = {1, 2, 1};
    cout << "Test Case 1: [1, 2, 1] -> " << sol.totalFruits(fruits1) << "\n"; // Output: 3

    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Test Case 2: [0, 1, 2, 2] -> " << sol.totalFruits(fruits2) << "\n"; // Output: 3

    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "Test Case 3: [1, 2, 3, 2, 2] -> " << sol.totalFruits(fruits3) << "\n"; // Output: 4

    vector<int> fruits4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Test Case 4: [3,3,3,1,2,1,1,2,3,3,4] -> " << sol.totalFruits(fruits4) << "\n"; // Output: 5

    return 0;
}