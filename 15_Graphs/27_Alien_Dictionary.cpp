/*
    Alien Dictionary
    Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.

    There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order.

    Examples:
    Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]
    Output: b d a c
    Explanation: 
    We will analyze every consecutive pair to find out the order of the characters.
    The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.
    The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.
    The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.
    The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.
    So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

    Input: N = 3, K = 3, dict = ["caa","aaa","aab"]
    Output: c a b
    Explanation: Similarly, if we analyze the consecutive pair 
    for this example, we will figure out [‘c’, ‘a’, ‘b’] is 
    a valid ordering.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K); // Graph with K nodes (0 to K-1)

        // Step 1: Build graph
        for (int i = 0; i < N - 1; ++i) {
            string w1 = dict[i];
            string w2 = dict[i + 1];
            int len = min(w1.size(), w2.size());
            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break; // only the first different character matters
                }
            }
        }

        // Step 2: Topological Sort (Kahn’s Algorithm)
        vector<int> inDegree(K, 0);
        for (int u = 0; u < K; ++u) {
            for (int v : adj[u])
                inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < K; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        string result;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            result += (char)(node + 'a');

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If topological sort doesn't include all characters, there was a cycle
        if (result.size() < K) return "";

        return result;
    }
};

// Utility to print the result
void printOrder(const string& order) {
    if (order.empty()) {
        cout << "Invalid ordering (cycle or missing info)" << endl;
    } else {
        for (char ch : order) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;

    // Example 1
    int N1 = 5, K1 = 4;
    string dict1[] = {"baa", "abcd", "abca", "cab", "cad"};
    string order1 = sol.findOrder(dict1, N1, K1);
    cout << "Example 1 Output: ";
    printOrder(order1);

    // Example 2
    int N2 = 3, K2 = 3;
    string dict2[] = {"caa", "aaa", "aab"};
    string order2 = sol.findOrder(dict2, N2, K2);
    cout << "Example 2 Output: ";
    printOrder(order2);

    return 0;
}

// Time: O(N × L + K + E)
// (L = average word length, E = total edges)
// Space: O(K + E)