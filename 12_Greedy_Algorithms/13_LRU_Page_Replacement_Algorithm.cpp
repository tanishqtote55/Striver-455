/*
    LRU Page Replacement Overview
    You are given a sequence of page references.
    You have a fixed number of page frames.

    When a page is referenced:
    If it’s already in memory → it's a hit.
    If not → it's a miss, and we:
    Evict the least recently used page if memory is full.
    Insert the new page.
*/
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class LRUPageReplacement {
private:
    int capacity;
    list<int> pages;  // Doubly linked list to maintain order (MRU at front, LRU at back)
    unordered_map<int, list<int>::iterator> pageMap; // Maps page number to its position in the list

public:
    LRUPageReplacement(int cap) {
        capacity = cap;
    }

    int processPages(const vector<int>& pageRefs) {
        int pageFaults = 0;

        for (int page : pageRefs) {
            // Page Hit: Move it to front
            if (pageMap.find(page) != pageMap.end()) {
                pages.erase(pageMap[page]);
                pages.push_front(page);
                pageMap[page] = pages.begin();
            }
            // Page Miss (Page Fault)
            else {
                pageFaults++;
                // Evict LRU if memory full
                if (pages.size() == capacity) {
                    int lru = pages.back();
                    pages.pop_back();
                    pageMap.erase(lru);
                }
                // Insert new page
                pages.push_front(page);
                pageMap[page] = pages.begin();
            }
        }

        return pageFaults;
    }

    void displayPages() {
        cout << "Pages in memory (MRU to LRU): ";
        for (int page : pages) {
            cout << page << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter number of page frames: ";
    cin >> capacity;

    int n;
    cout << "Enter number of page references: ";
    cin >> n;

    vector<int> pageRefs(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; ++i) {
        cin >> pageRefs[i];
    }

    LRUPageReplacement lru(capacity);
    int faults = lru.processPages(pageRefs);

    cout << "\nTotal Page Faults: " << faults << endl;
    lru.displayPages(); // Final memory state

    return 0;
}

// | Operation          | Time |
// | ------------------ | ---- |
// | Page Access        | O(1) |
// | Insertion/Eviction | O(1) |

