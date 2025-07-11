/*
    Here is the complete content formatted neatly for **copy-pasting into MS Word**. You can paste this directly into Word — the formatting (headings, bullet points, tables) will remain clear and editable:

    ---

    ---

    ## 🧠 BITWISE PREREQUISITES

    ### 1. **Binary Representation**

    * Understand how integers are represented in **binary** (base 2).
    * Example: `5 → 101`, `10 → 1010`

    ### 2. **Bitwise Operators**

    | Operator    | Symbol | Meaning                 | Example                       |     |         |                 |
    | ----------- | ------ | ----------------------- | ----------------------------- | --- | ------- | --------------- |
    | AND         | `&`    | Bitwise AND             | `5 & 3 → 101 & 011 = 001 → 1` |     |         |                 |
    | OR          | \`     | \`                      | Bitwise OR                    | \`5 | 3 → 101 | 011 = 111 → 7\` |
    | XOR         | `^`    | Bitwise XOR             | `5 ^ 3 → 101 ^ 011 = 110 → 6` |     |         |                 |
    | NOT         | `~`    | Bitwise NOT             | `~5 → ~(00000101) = 11111010` |     |         |                 |
    | Left Shift  | `<<`   | Multiply by powers of 2 | `5 << 1 → 10`                 |     |         |                 |
    | Right Shift | `>>`   | Divide by powers of 2   | `10 >> 1 → 5`                 |     |         |                 |

    ### 3. **Checking and Setting Bits**

    * **Check if i-th bit is set**:

    ```cpp
    if ((n >> i) & 1)
    ```
    * **Set i-th bit**:

    ```cpp
    n |= (1 << i);
    ```
    * **Clear i-th bit**:

    ```cpp
    n &= ~(1 << i);
    ```
    * **Toggle i-th bit**:

    ```cpp
    n ^= (1 << i);
    ```

    ### 4. **Most Significant Bit (MSB) / Highest Bit**

    * Useful for maximum XOR problems.
    * Use `log2(n)` or `31 - __builtin_clz(n)` (in GCC/Clang) to find position.

    ---

    ## 🌲 TRIE THEORY FOR STRINGS

    ### ✅ Basics of Trie:

    * A **Trie** is a tree-like data structure used for efficient storage and retrieval of strings, especially useful for:

    * Word Dictionary
    * Prefix Search
    * Autocomplete
    * Distinct Substrings

    ### ✅ Structure:

    Each node contains:

    * Array or Map of children (size 26 for lowercase a-z)
    * `isEndOfWord` flag (optional, to mark end of word)
    * Additional counters (for advanced operations like count prefix)

    ---

    ## 🔐 TRIE THEORY FOR BITS

    When numbers (not strings) are involved, we use a **Binary Trie** (Bitwise Trie).

    ### ✅ Use-Cases of Bitwise Trie:

    1. **Maximum XOR of two numbers in an array**
    2. **Count of pairs with XOR in a range**
    3. **Number of distinct substrings of binary string**
    4. **Minimum XOR pair in an array**

    ### ✅ Structure:

    Each node has:

    * `child[0]` → represents bit `0`
    * `child[1]` → represents bit `1`

    For 32-bit integers:

    * Traverse bits from 31 → 0 (MSB to LSB)
    * Store all numbers in the Trie using their bit representation

    ---

    ## ✨ Examples of Trie Problems Using Bits:

    | Problem                        | Approach                                                            |
    | ------------------------------ | ------------------------------------------------------------------- |
    | Maximum XOR of two numbers     | Insert numbers into binary Trie and search greedy for opposite bits |
    | Count pairs with XOR in range  | Use Trie to count how many prefixes satisfy condition               |
    | Distinct substrings            | Insert all suffixes in Trie (string-based)                          |
    | Longest word with all prefixes | Use standard Trie and validate all prefixes                         |

    ---

    ## 🧩 Summary of Prerequisites:

    | Topic                 | Why It's Needed                       |
    | --------------------- | ------------------------------------- |
    | Binary representation | To build bitwise tries                |
    | Bitwise operators     | XOR, AND used in max/min XOR problems |
    | Trie structure basics | Core data structure for prefixes      |
    | MSB position logic    | Optimize Trie depth for bit length    |

    ---

    You can now paste this into Word and optionally add headings, borders, or styles for better presentation.
    Let me know if you'd like a **PDF version**, **LaTeX version**, or printable **cheat sheet** layout.

*/