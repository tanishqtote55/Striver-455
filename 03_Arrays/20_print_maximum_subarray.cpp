#include <iostream>
#include <vector>
using namespace std;

pair<int, pair<int, int>> maxSubarrayWithIndices(vector<int> &nums) {
    int max_curr = nums[0];
    int max_global = nums[0];
    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > max_curr + nums[i]) {
            max_curr = nums[i];
            tempStart = i;
        } else {
            max_curr += nums[i];
        }
        
        if (max_curr > max_global) {
            max_global = max_curr;
            start = tempStart;
            end = i;
        }
    }
    return {max_global, {start, end}};
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    auto result = maxSubarrayWithIndices(nums);
    int maxsum = result.first;
    int start = result.second.first;
    int end = result.second.second;

    cout << "Maximum Subarray Sum = " << maxsum << '\n';
    cout << "Subarray elements are: "; 
    for(int i = start; i <= end; i++) {
        cout << nums[i] << " "; 
    }
    cout << '\n';

    return 0;
}
