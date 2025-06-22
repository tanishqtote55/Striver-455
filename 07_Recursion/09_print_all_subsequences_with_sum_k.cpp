#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Print All Subsequences
    // void printS(int index, vector<int> &ds, int s, int sum, vector<int> arr, int n){
    //     if(index == n){
    //         if(s == sum){
    //             for(auto it: ds) cout << it << " ";
    //             cout << endl;
    //         }
    //         return;
    //     } 
    //     // take or pick the particular index into the subsequence
    //     ds.push_back(arr[index]);
    //     s += arr[index];
    //     printS(index + 1, ds, s, sum, arr, n);
    //     ds.pop_back();
    //     // not take or not pick the particular index into the subsequence
    //     s -= arr[index];
    //     printS(index + 1, ds, s, sum, arr, n);
    // }

    // Print Any Subsequences using Boolean Flag
    // bool flag = false;
    // void printS(int index, vector<int> &ds, int s, int sum, vector<int> arr, int n){
    //     if(index == n){
    //         if(s == sum && flag == false){
    //             flag = true;
    //             for(auto it: ds) cout << it << " ";
    //             cout << endl;
    //         }
    //         return;
    //     } 
    //     // take or pick the particular index into the subsequence
    //     ds.push_back(arr[index]);
    //     s += arr[index];
    //     printS(index + 1, ds, s, sum, arr, n);
    //     ds.pop_back();
    //     // not take or not pick the particular index into the subsequence
    //     s -= arr[index];
    //     printS(index + 1, ds, s, sum, arr, n);
    // }

    // Print Any Subsequences using Boolean Function
    // bool printS(int index, vector<int> &ds, int s, int sum, vector<int> arr, int n){
    //     if(index == n){
    //         // Condition Satisfied
    //         if(s == sum){
    //             for(auto it: ds) cout << it << " ";
    //             cout << endl;
    //             return true;
    //         }
    //         // Condition Not Satisfied
    //         else return false;;
    //     } 
    //     // take or pick the particular index into the subsequence
    //     ds.push_back(arr[index]);
    //     s += arr[index];
    //     if(printS(index + 1, ds, s, sum, arr, n) == true){
    //         return true;
    //     }
    //     ds.pop_back();
    //     // not take or not pick the particular index into the subsequence
    //     s -= arr[index];
    //     if(printS(index + 1, ds, s, sum, arr, n) == true ){
    //         return true;
    //     }
    //     return false;
    // }

    // Count the Number of Subsequences  
    int printS(int index, vector<int> &ds, int s, int sum, vector<int> arr, int n){
        // Condition not satisfied
        // strictly done if array contains positives only
        if(s > sum) return 0;
        if(index == n){
            // Condition Satisfied
            if(s == sum) return 1;
            // Condition Not Satisfied
            else return 0;
        } 
        // take or pick the particular index into the subsequence
        ds.push_back(arr[index]);
        s += arr[index];
        int l = printS(index + 1, ds, s, sum, arr, n);
        ds.pop_back();
        // not take or not pick the particular index into the subsequence
        s -= arr[index];
        int r = printS(index + 1, ds, s, sum, arr, n);
        return l + r;
    }
};

// Main function to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    // sol.printS(0, ds, 0, sum, nums, n);
    cout << sol.printS(0, ds, 0, sum, nums, n);

    return 0;
}
