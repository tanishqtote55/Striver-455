#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> rank;
    int r = 1;

    for (int val : sortedArr) {
        if (rank.find(val) == rank.end()) {
            rank[val] = r++;
        }
    }

    vector<int> result;
    for (int val : arr) {
        result.push_back(rank[val]);
    }

    return result;
}

int main() {
    vector<int> arr = {40, 10, 20, 20, 30};

    vector<int> ranked = arrayRankTransform(arr);

    cout << "Ranked Array: ";
    for (int val : ranked) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
