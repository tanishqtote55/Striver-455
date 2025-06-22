#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void printS(int index, vector<int> &ds, int s, int sum, vector<int> arr, int n){
        if(index == n){
            if(s == sum){
                for(auto it: ds) cout << it << " ";
                cout << endl;
            }
            return;
        } 
        // take or pick the particular index into the subsequence
        ds.push_back(arr[index]);
        s += arr[index];
        printS(index + 1, ds, s, sum, arr, n);
        ds.pop_back();
        // not take or not pick the particular index into the subsequence
        s -= arr[index];
        printS(index + 1, ds, s, sum, arr, n);
    }
};

// Main function to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    sol.printS(0, ds, 0, sum, nums, n);

    return 0;
}
