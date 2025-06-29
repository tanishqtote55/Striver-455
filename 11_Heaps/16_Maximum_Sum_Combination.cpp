/*
    Problem Statement
    Given two integer arrays A and B, both of size N, find the K maximum sum combinations from all the possible sums formed by picking one element from A and one from B.

    Example
    Input:
    A = [1, 4, 2, 3]
    B = [2, 5, 1, 6]
    K = 4
    Output:
    [10, 9, 9, 8]
    Explanation:
    All possible sums (some of them):
    4+6=10
    3+6=9
    4+5=9
    2+6=8
    ...
    Return the top K sums.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<int> maxSumCombination(vector<int>& A, vector<int>& B, int K) {
    int N = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<tuple<int, int, int>> maxHeap; // {sum, i, j}
    set<pair<int, int>> used; // To avoid duplicates

    int i = N - 1, j = N - 1;
    maxHeap.push({A[i] + B[j], i, j});
    used.insert({i, j});

    vector<int> result;

    while (K-- && !maxHeap.empty()) {
        auto [sum, i, j] = maxHeap.top(); maxHeap.pop();
        result.push_back(sum);

        if (i - 1 >= 0 && !used.count({i - 1, j})) {
            maxHeap.push({A[i - 1] + B[j], i - 1, j});
            used.insert({i - 1, j});
        }

        if (j - 1 >= 0 && !used.count({i, j - 1})) {
            maxHeap.push({A[i] + B[j - 1], i, j - 1});
            used.insert({i, j - 1});
        }
    }

    return result;
}
int main() {
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int K = 4;

    vector<int> res = maxSumCombination(A, B, K);
    cout << "Top " << K << " Maximum Sum Combinations: ";
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
