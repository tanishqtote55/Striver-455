/*
    ### 📚 Introduction to Dynamic Programming (DP)

    **Dynamic Programming (DP)** is a powerful algorithmic technique used to solve problems by breaking them down into simpler subproblems and storing the results of these subproblems to avoid redundant work.

    ---

    ### 🔁 Why Use Dynamic Programming?

    Many problems have **overlapping subproblems** and **optimal substructure**. Solving such problems using brute force leads to exponential time complexity. DP solves them efficiently by:

    1. **Avoiding recomputation** (by storing results in a table - also called **memoization** or **tabulation**).
    2. **Reusing previously computed results** for solving larger problems.

    ---

    ### ✌️ Two Key Properties of DP Problems

    | Property                       | Explanation                                                                                     |
    | ------------------------------ | ----------------------------------------------------------------------------------------------- |
    | 1. **Overlapping Subproblems** | The problem can be broken down into smaller, reusable subproblems.                              |
    | 2. **Optimal Substructure**    | The optimal solution of the overall problem depends on the optimal solution of its subproblems. |

    ---

    ### ⚔️ Approaches in DP

    | Approach                      | Description                                                             |
    | ----------------------------- | ----------------------------------------------------------------------- |
    | 1. **Top-Down (Memoization)** | Solve the problem recursively and store the results of subproblems.     |
    | 2. **Bottom-Up (Tabulation)** | Solve subproblems first and use them to build the solution iteratively. |

    ---

    ### 🧠 Classic Examples of DP Problems

    | Problem                              | Description                                         |
    | ------------------------------------ | --------------------------------------------------- |
    | Fibonacci Numbers                    | `f(n) = f(n-1) + f(n-2)`                            |
    | 0/1 Knapsack Problem                 | Maximize value with given weight capacity           |
    | Longest Common Subsequence (LCS)     | Find longest sequence present in both strings       |
    | Longest Increasing Subsequence (LIS) | Find longest increasing sequence in array           |
    | Matrix Chain Multiplication          | Minimize cost of matrix multiplication              |
    | Coin Change                          | Find min number of coins to make a value            |
    | Edit Distance                        | Minimum operations to convert one string to another |
    | Subset Sum                           | Determine if a subset sums to a given value         |

    ---

    ### 🛠️ Basic Template for DP (Memoization)

    ```cpp
    int dp[n+1]; // initialized to -1
    int solve(int n) {
        if (n == 0 || n == 1) return n;

        if (dp[n] != -1) return dp[n];

        return dp[n] = solve(n - 1) + solve(n - 2);
    }
    ```

    ---

    ### 📈 Time Complexity Benefits

    | Approach    | Time Complexity (e.g., Fibonacci) |
    | ----------- | --------------------------------- |
    | Brute Force | Exponential `O(2^n)`              |
    | With DP     | Linear `O(n)`                     |

    ---

    ### 💡 Tips to Master DP

    * Learn to **identify subproblems**.
    * Try both **memoization and tabulation** for a problem.
    * Draw **state transition diagrams** or tables.
    * Practice standard problems (see Leetcode, GFG, Striver’s DP Series).
    * Understand **space optimization** (using fewer variables instead of arrays).

    ---

    Would you like a roadmap or a list of 10 beginner-friendly problems to start with?
*/