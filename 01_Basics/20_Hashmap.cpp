#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // pre-compute

    // Storing and Fetching in the map -> O(logn)
    // Storing and Fetching in the unordered_map -> O(1) Worst Case -> O(n) due to Collision in Division Method
    
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // iterate in the map 
    for(auto it: mpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}