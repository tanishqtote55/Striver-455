/*
    735. Asteroid Collision
    We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

    For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

    Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

    Example 1:

    Input: asteroids = [5,10,-5]
    Output: [5,10]
    Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
    Example 2:

    Input: asteroids = [8,-8]
    Output: []
    Explanation: The 8 and -8 collide exploding each other.
    Example 3:

    Input: asteroids = [10,2,-5]
    Output: [10]
    Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
    
    Constraints:

    2 <= asteroids.length <= 104
    -1000 <= asteroids[i] <= 1000
    asteroids[i] != 0
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a: asteroids){
            bool destroyed = false;
            while(!st.empty() && a < 0 && st.top() > 0){
                if(abs(a) > st.top()){
                    st.pop();
                } else if(abs(a) == st.top()){
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) st.push(a);
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = sol.asteroidCollision(asteroids1);
    cout << "Result 1: ";
    for (int a : result1) cout << a << " ";
    cout << endl;

    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = sol.asteroidCollision(asteroids2);
    cout << "Result 2: ";
    for (int a : result2) cout << a << " ";
    cout << endl;

    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = sol.asteroidCollision(asteroids3);
    cout << "Result 3: ";
    for (int a : result3) cout << a << " ";
    cout << endl;

    return 0;
}

// | Metric           | Value    |
// | ---------------- | -------- |
// | Time Complexity  | **O(n)** |
// | Space Complexity | **O(n)** |
