/*
    460. LFU Cache
    Design and implement a data structure for a Least Frequently Used (LFU) cache.

    Implement the LFUCache class:

    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
    To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

    When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

    The functions get and put must each run in O(1) average time complexity.

    Example 1:

    Input
    ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
    Output
    [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

    Explanation
    // cnt(x) = the use counter for key x
    // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
    LFUCache lfu = new LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);      // return -1 (not found)
    lfu.get(3);      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);      // return 4
                    // cache=[4,3], cnt(4)=2, cnt(3)=3
    
    Constraints:

    1 <= capacity <= 104
    0 <= key <= 105
    0 <= value <= 109
    At most 2 * 105 calls will be made to get and put.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class LFUCache {
public:
    class Node {
    public:
        int key, val, freq;
        Node *prev, *next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            freq = 1;
        }
    };

    class DLL {
    public:
        Node *head, *tail;
        int size;
        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node *node) {
            Node *temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++;
        }

        void removeNode(Node *node) {
            Node *prev = node->prev;
            Node *next = node->next;
            prev->next = next;
            next->prev = prev;
            size--;
        }

        Node* removeLast() {
            if (size == 0) return nullptr;
            Node *last = tail->prev;
            removeNode(last);
            return last;
        }
    };

    int cap, minFreq;
    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqMap[oldFreq]->removeNode(node);
        if (freqMap[oldFreq]->size == 0 && oldFreq == minFreq) {
            minFreq++;
        }

        node->freq++;
        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DLL();
        }
        freqMap[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;
        Node *node = keyMap[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyMap.find(key) != keyMap.end()) {
            Node *node = keyMap[key];
            node->val = value;
            updateFreq(node);
        } else {
            if (keyMap.size() == cap) {
                Node *delNode = freqMap[minFreq]->removeLast();
                keyMap.erase(delNode->key);
            }
            Node *newNode = new Node(key, value);
            minFreq = 1;
            if (freqMap.find(1) == freqMap.end()) {
                freqMap[1] = new DLL();
            }
            freqMap[1]->addFront(newNode);
            keyMap[key] = newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4
    return 0;
}