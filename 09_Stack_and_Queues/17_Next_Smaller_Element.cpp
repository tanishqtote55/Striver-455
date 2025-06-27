#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // will store indices or values (monotonic increasing)

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(nums[i]);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};

    vector<int> result = nextSmallerElements(nums);

    cout << "Next smaller elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
