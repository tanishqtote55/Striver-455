/*
    23. Merge k Sorted Lists
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:

    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6
    Example 2:

    Input: lists = []
    Output: []
    Example 3:

    Input: lists = [[]]
    Output: []
    
    Constraints:

    k == lists.length
    0 <= k <= 104
    0 <= lists[i].length <= 500
    -104 <= lists[i][j] <= 104
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 104.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on val
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Add the head of each list to the heap
        for (auto list : lists) {
            if (list != nullptr)
                minHeap.push(list);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != nullptr)
                minHeap.push(node->next);
        }

        return dummy.next;
    }
};

// Helper to build a linked list from vector
ListNode* buildList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : vals) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Sample input: [[1,4,5],[1,3,4],[2,6]]
    vector<vector<int>> input = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<ListNode*> lists;
    for (const auto& vec : input) {
        lists.push_back(buildList(vec));
    }

    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}