/*
    621. Task Scheduler
    You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

    Return the minimum number of CPU intervals required to complete all tasks.

    Example 1:
    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
    After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

    Example 2:
    Input: tasks = ["A","C","A","B","D","B"], n = 1
    Output: 6
    Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
    With a cooling interval of 1, you can repeat a task after just one other task.

    Example 3:
    Input: tasks = ["A","A","A", "B","B","B"], n = 3
    Output: 10
    Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
    There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

    Constraints:
    1 <= tasks.length <= 104
    tasks[i] is an uppercase English letter.
    0 <= n <= 100
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = count(freq.begin(), freq.end(), maxFreq);

        int partCount = maxFreq - 1;
        int partLength = n + 1;
        int emptySlots = partCount * partLength + maxCount;

        return max((int)tasks.size(), emptySlots);
    }
};

// Helper to convert a string like "AAABBB" to vector<char>
vector<char> stringToTaskVector(const string& s) {
    return vector<char>(s.begin(), s.end());
}

int main() {
    Solution sol;

    vector<char> tasks1 = stringToTaskVector("AAABBB");
    int n1 = 2;
    cout << "Output 1: " << sol.leastInterval(tasks1, n1) << endl;  // Expected: 8

    vector<char> tasks2 = stringToTaskVector("ACABDB");
    int n2 = 1;
    cout << "Output 2: " << sol.leastInterval(tasks2, n2) << endl;  // Expected: 6

    vector<char> tasks3 = stringToTaskVector("AAABBB");
    int n3 = 3;
    cout << "Output 3: " << sol.leastInterval(tasks3, n3) << endl;  // Expected: 10

    vector<char> tasks4 = stringToTaskVector("AABB");
    int n4 = 0;
    cout << "Output 4: " << sol.leastInterval(tasks4, n4) << endl;  // Expected: 4

    return 0;
}