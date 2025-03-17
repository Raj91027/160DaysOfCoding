/*
Write program to calculate pow(b, e)

Given two numbers b and e, the task is to implement a function to compute b^e.

Examples: 

Input: b = 3.00000, e = 5
Output: 243.00000

Input: b = 0.55000, e = 3
Output: 0.16638

Input: b = -0.67000, e = -7
Output: -16.49971
*/

//[Naive Approach 1] Using Iteration - O(e) Time and O(1) Space
//The idea is to simply multiply b exactly e times using a iterative loop.


// C++ program to calculate pow(b, e)
#include <iostream>
using namespace std;

// Naive iterative solution to calculate pow(b, e)
double power(double b, int e) {
  
    // Initialize result to 1
    double pow = 1;

    // Multiply x for n times
    for (int i = 0; i < abs(e); i++) 
        pow = pow * b;
  	
  	if (e < 0)
      	return 1/pow;

    return pow;
}

int main() {
    double b = 3.0;
    int e = 5;
    double res = power(b, e);
    cout << res;
    return 0;
}


//[Optimized Approach 2] Using Recursion - O(log e) Time and O(log e) Space
//The idea is to divide the problem into subproblems of size e/2 and call the function recursively.
//If e is even, then the result is b^(e/2) * b^(e/2).
//If e is odd, then the result is b * b^(e/2) * b^(e/2).

// C++ program to calculate pow(b, e)
#include <iostream>
using namespace std;

// Optimized recursive solution to calculate pow(b, e)
double power(double b, int e) {
  
    // Base case
    if (e == 0)
        return 1;
  
    // Recursive call
    double temp = power(b, e / 2);
  
    // If e is even
    if (e % 2 == 0)
        return temp * temp;
  
    // If e is odd
    else {
        if (e > 0)
            return b * temp * temp;
        else
            return (temp * temp) / b;
    }
}

int main() {
    double b = 3.0;
    int e = 5;
    double res = power(b, e);
    cout << res;
    return 0;
}

// Time Complexity: O(log e)
// Space Complexity: O(log e)


//[Optimized Approach 3] Using Bitwise Operators - O(log e) Time and O(1) Space
//The idea is to use bitwise operators to calculate the power of a number.
//The idea is to divide the problem into subproblems of size e/2 and call the function recursively.
//If e is even, then the result is b^(e/2) * b^(e/2).
//If e is odd, then the result is b * b^(e/2) * b^(e/2).

// C++ program to calculate pow(b, e)
#include <iostream>
using namespace std;

// Optimized recursive solution to calculate pow(b, e)

double power(double b, int e) {
  
    // Base case
    if (e == 0)
        return 1;
  
    // Recursive call
    double temp = power(b, e >> 1);
  
    // If e is even
    if (e % 2 == 0)
        return temp * temp;
  
    // If e is odd
    else {
        if (e > 0)
            return b * temp * temp;
        else
            return (temp * temp) / b;
    }
}

int main() {
    double b = 3.0;
    int e = 5;
    double res = power(b, e);
    cout << res;
    return 0;
}

// Time Complexity: O(log e)
// Space Complexity: O(1)

