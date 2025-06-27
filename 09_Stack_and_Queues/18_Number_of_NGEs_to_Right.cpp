#include <iostream>
#include <vector>
using namespace std;

vector<int> countNGEsRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] > nums[i]) {
                count++;
            }
        }
        result[i] = count;
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};

    vector<int> result = countNGEsRight(nums);

    cout << "Number of NGEs to the right:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
