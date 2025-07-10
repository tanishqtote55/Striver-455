/*
    210. Course Schedule II

    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

    Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: [0,1]
    Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

    Example 2:
    Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
    So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
    
    Example 3:
    Input: numCourses = 1, prerequisites = []
    Output: [0]
    
    Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= numCourses * (numCourses - 1)
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    ai != bi
    All the pairs [ai, bi] are distinct.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Step 1: Build graph and in-degree
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        // Step 2: Push all courses with in-degree 0
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;

        // Step 3: Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 4: Check if topological sort is valid (i.e., no cycle)
        if (topoOrder.size() == numCourses)
            return topoOrder;

        return {}; // Return empty vector if cycle is detected
    }
};

void printVector(const vector<int>& v) {
    if (v.empty()) {
        cout << "[]\n";
        return;
    }

    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Example 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Example 1 Output: ";
    printVector(sol.findOrder(numCourses1, prerequisites1));

    // Example 2
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Example 2 Output: ";
    printVector(sol.findOrder(numCourses2, prerequisites2));

    // Example 3 (cycle exists)
    int numCourses3 = 2;
    vector<vector<int>> prerequisites3 = {{1, 0}, {0, 1}};
    cout << "Example 3 Output: ";
    printVector(sol.findOrder(numCourses3, prerequisites3));

    return 0;
}

// Time: O(V + E)
// Space: O(V + E)
// Where V = numCourses, E = prerequisites.size().