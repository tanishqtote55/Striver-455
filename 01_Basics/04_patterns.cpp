#include <iostream>
#include <math.h>
using namespace std;    
// https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa/
/*
    Sam is making a forest visualizer. An N-dimensional forest is represented by the pattern of size NxN filled with ‘*’.
    For every value of ‘N’, help sam to print the corresponding N-dimensional forest.

    Example:
    Input: ‘N’ = 3

    Output: 
    * * *
    * * *
    * * *
*/

void nForest(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is making a forest visualizer. An N-dimensional forest is represented by the pattern of size NxN filled with ‘*’.

    An N/2-dimensional forest is represented by the lower triangle of the pattern filled with ‘*’.

    For every value of ‘N’, help sam to print the corresponding N/2-dimensional forest.

    Example:
    Input:  ‘N’ = 3

    Output: 
    * 
    * *
    * * *
*/

void nBy2Forest(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}       

/*
    Problem statement
    Sam is making a Triangular painting for a maths project.

    An N-dimensional Triangle is represented by the lower triangle of the pattern filled with integers starting from 1.

    For every value of ‘N’, help sam to print the corresponding N-dimensional Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 
    1
    1 2 
    1 2 3
*/

void nTriangle(int n) {
    for (int i = 1; i <= n; i++) {        
        for (int j = 1; j <= i; j++) {    
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is making a Triangular painting for a maths project.

    An N-dimensional Triangle is represented by the lower triangle of the pattern filled with integers representing the row number.

    For every value of ‘N’, help sam to print the corresponding Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 
    1
    2 2 
    3 3 3
*/

void nTriangleSimilar(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is planting trees on the upper half region (separated by the left diagonal) of the square shared field.

    For every value of ‘N’, print the field if the trees are represented by ‘*’.

    Example:
    Input: ‘N’ = 3

    Output: 
    * * *
    * *
    *
*/

void seeding(int n) {
	// Write your code here.
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
		cout << endl;
	}
}

/*
    Problem statement
    Aryan and his friends are very fond of the pattern. For a given integer ‘N’, they want to make the Reverse N-Number Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 

    1 2 3
    1 2
    1
*/

void seedingNumbers(int n) {
	// Write your code here.
	for(int i = 0; i < n; i++){
		for (int j = 1; j <= n - i; j++) {
            cout << j << " ";
        }
		cout << endl;
	}
}

/*
    Problem statement
    Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the N-Star Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 

      *
     ***
    *****
*/

void nStarTriangle(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            cout << " ";
        }
        for(int j = 1; j <= (2 * i - 1); j++){
            cout << "*";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the Reverse N-Star Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 

    *****
     ***
      *
*/

void reverseNStarTriangle(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            cout << " ";
        }
        for(int j = 1; j <= (n - i) * 2 + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the N-Star Diamond.

    Example:
    Input: ‘N’ = 3

    Output: 

      *
     ***
    *****
    *****
     ***
      *
*/

void nStarDiamond(int n) {
    // Write your code here.
    nStarTriangle(n);
    reverseNStarTriangle(n);
}

/*
    Problem statement
    Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the N-Star Rotated Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 

    *
    **
    ***
    **
    *
*/

void nStarDiamondTriangle(int n) {
    // Write your code here.
    // // nBy2Forest(n);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // // seeding(n); It should not print all stars in the start
    // for(int i = 0; i < n; i++){
	// 	for (int j = 1; j < n - i; j++) {
    //         cout << "*";
    //     }
	// 	cout << endl;
	// }

    for(int i = 1; i <= 2*n-1; i++){
        int stars = i;
        if(i > n) stars = 2 * n - i;
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Aryan and his friends are very fond of the pattern. For a given integer ‘N’, they want to make the N-Binary Number Triangle.

    You are required to print the pattern as shown in the examples below.

    Example:
    Input: ‘N’ = 3

    Output: 

    1
    0 1
    1 0 1
*/

void nBinaryTriangle(int n) {
    // Write your code here.
    for(int i = 0; i < n; i++){
        int start = 1;
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j <= i; j++){
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

/*
    Problem statement
    Aryan and his friends are very fond of the pattern. They want to make the Reverse N-Number Crown for a given integer' N'.

    Given 'N', print the corresponding pattern.

    Example:
    Input: ‘N’ = 3

    Output: 

    1         1
    1 2     2 1
    1 2 3 3 2 1
*/

void numberCrown(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << j << " ";
        }
        for(int j = 1; j <= (n - i) * 4; j++){
            cout << " ";
        }
        for(int j = i; j >= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Aryan and his friends are very fond of patterns. For a given integer ‘N’, they want to make the Increasing Number Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 

    1
    2 3
    4 5 6
*/

void nNumberTriangle(int n) {
    // Write your code here.
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << num << " ";
            num += 1;
        }
        cout << endl;
    }
}

/*
    Problem statement
    Aryan and his friends are very fond of patterns. For a given integer ‘N’, they want to make the Increasing Letter Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 

    A
    A B
    A B C
*/

void nLetterTriangle(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        for(char ch = 'A'; ch < 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Aryan and his friends are very fond of patterns. For a given integer ‘N’, they want to make the Reverse Letter Triangle.

    You must print a matrix corresponding to the given Reverse Letter Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 

    A B C
    A B
    A
*/

void reverseNLetterTriangle(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        for(char ch = 'A'; ch <= 'A' + (n - i); ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is curious about Alpha-Ramp, so he decided to create Alpha-Ramp of different sizes.

    An Alpha-Ramp is represented by a triangle, where alphabets are filled from the top in order.

    For every value of ‘N’, help sam to return the corresponding Alpha-Ramp.

    Example:
    Input: ‘N’ = 3

    Output: 
    A
    B B
    C C C
*/

void alphaRamp(int n) {
    // Write your code here.
    for(int i = 0; i < n; i++){
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is curious about Alpha-Hills, so he decided to create Alpha-Hills of different sizes.

    An Alpha-hill is represented by a triangle, where alphabets are filled in palindromic order.

    For every value of ‘N’, help sam to return the corresponding Alpha-Hill.

    Example:
    Input: ‘N’ = 3

    Output: 
        A
      A B A
    A B C B A
*/

void alphaHill(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2* (n - i); j++){
            cout << " ";
        }
        char ch = 'A';
        for(int j = 1; j <= (2 * i - 1); j++){
            cout << ch << " ";
            if(j >= ((2 * i) / 2)){
                ch--;
            }
            else{
                ch++;
            }
        }
        for(int j = 1; j <= 2 * (n - i); j++){
            cout << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is researching on Alpha-Triangles. So, he needs to create them for different integers ‘N’.

    An Alpha-Triangle is represented by the triangular pattern of alphabets in reverse order.

    For every value of ‘N’, help sam to print the corresponding Alpha-Triangle.

    Example:
    Input: ‘N’ = 3

    Output: 
    C
    C B 
    C B A
*/

void alphaTriangle(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        char ch = 'A' + (n - 1); 
        for(int j = 1; j <= i; j++){
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}

void alphaTriangle2(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        char ch = 'A' + (n - i); 
        for(int j = 1; j <= i; j++){
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is curious about symmetric patterns, so he decided to create one.

    For every value of ‘N’, return the symmetry as shown in the example.

    Example:
    Input: ‘N’ = 3

    Output: 
    * * * * * * 
    * *     * * 
    *         * 
    *         * 
    * *     * * 
    * * * * * * 
    Detailed expl
*/

void symmetry(int n) {
    // Write your code here.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n- i); j++){
            cout << "* ";
        }
        for(int j = 0; j < (4 * i); j++){
            cout << " ";
        }
        for(int j = 0; j < (n - i); j++){
            cout << "* ";
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            cout << "* ";
        }
        for(int j = 0; j < (4 * (n - i)); j++){
            cout << " ";
        }
        for(int j = 0; j < i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Sam is curious about symmetric patterns, so he decided to create one.

    For every value of ‘N’, return the symmetry as shown in the example.

    Example:
    Input: ‘N’ = 3

    Output: 
    *         *
    * *     * *
    * * * * * *
    * *     * *
    *         *
*/

void symmetryNew(int n) {
    // Write your code here.
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            cout << "* ";
        }
        for(int j = 0; j < (4 * (n - i)); j++){
            cout << " ";
        }
        for(int j = 0; j < i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < (n- i); j++){
            cout << "* ";
        }
        for(int j = 0; j < (4 * i); j++){
            cout << " ";
        }
        for(int j = 0; j < (n - i); j++){
            cout << "* ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Ninja has been given a task to print the required star pattern and he asked your help for the same.

    You must return an ‘N’*’N’ matrix corresponding to the given star pattern.

    Example:
    Input: ‘N’ = 4

    Output: 

    ****
    *  *
    *  *
    ****
*/

void getStarPattern(int n) {
    // Write your code here.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1){
                cout << "*";
            }
            else cout << " ";
        }
        cout << endl;
    }
}

/*
    Problem statement
    Ninja has been given a task to print the required pattern and he asked for your help with the same.

    You must print a matrix corresponding to the given number pattern.

    Example:
    Input: ‘N’ = 4

    Output: 

    4444444
    4333334
    4322234
    4321234
    4322234
    4333334
    4444444
*/

void getNumberPattern(int n) {
    // Write your code here.
    for(int i = 0; i < 2 * n - 1; i++){
        for(int j = 0; j < 2 * n - 1; j++){
            int top = i;
            int left = j;
            int bottom = (2 * n - 1) - 1 - i;
            int right = (2 * n - 1) - 1 - j;
            // Find minimum distance from any edge
            int minDist = min(min(top, left), min(bottom, right));
            
            // The value at position (i,j) is n - minDist
            cout << n - minDist;
        }
        cout << endl; 
    }
}

int main() {
    int n;
    cin >> n;        
    nForest(n);      
    nBy2Forest(n);
    nTriangle(n);
    nTriangleSimilar(n);
    seeding(n);
    seedingNumbers(n);
    nStarTriangle(n);
    reverseNStarTriangle(n);
    nStarDiamond(n);
    nStarDiamondTriangle(n);
    nBinaryTriangle(n);
    numberCrown(n);
    nNumberTriangle(n);
    nLetterTriangle(n);
    reverseNLetterTriangle(n);
    alphaRamp(n);
    alphaHill(n);
    alphaTriangle(n);
    alphaTriangle2(n);
    symmetry(n);
    symmetryNew(n);
    getStarPattern(n);
    getNumberPattern(n);
    return 0;
}