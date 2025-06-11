/*
Case 1 - If the string contains only lowercase letters: In this case, we can map the characters like:
‘a’ -> 0, ‘b’ -> 1, ‘c’ -> 2,....., ‘z’ -> 25.
In order to get the corresponding value for a character, we will use the following formula:
corresponding value = given character - 'a'
For example, if the given character is ‘f’, we will get the value as (‘f’ - ‘a’) = (102-97) = 5.  Here, we can easily observe that the maximum value can be 25.
So, for character hashing in this case, we need a hash array of size 26. And while pre-storing we will do hash[s[i]-’a’] += 1 instead of hash[arr[i]] += 1, and while fetching we will do hash[character-’a’] instead of hash[number]. The rest of the methods will be as same as in the case of number hashing.

Case 2 -  If the string contains only uppercase letters: In this case, we can map the characters like:
‘A’ -> 0, ‘B’ -> 1, ‘C’ -> 2,....., ‘Z’ -> 25. 
In order to get the corresponding value for a character, we will use the following formula:
corresponding value = given character - 'A'
Then the process will be similar to case 1.

Case 3 - If the string contains both uppercase and lowercase letters: We have 256 characters in total in this case. So, we will create a hash array of size 256. We will not subtract anything from the given character and will use the character as it is, to access the hash array while pre-storing and fetching. For pre-storing hash[s[i]] += 1 and for fetching we will use hash[character] only. The rest of the process will be exactly the same as in the number hashing.
Note: The case 3 method also applies to case 1 and case 2. In character hashing, the limit will not cross 256 and so we will always use this method.
*/
#include <iostream>
using namespace std;

int main() {

    string s;
    cin >> s;

    //precompute: for lowercase hashing
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    //precompute: for uppercase hashing
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'A']++;
    }

    //precompute: for 256 characters
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetch:
        cout << hash[c - 'a'] << endl;
        cout << hash[c - 'A'] << endl;
        cout << hash[c] << endl;
    }
    return 0;
}
