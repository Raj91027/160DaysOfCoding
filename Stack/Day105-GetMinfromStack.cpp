/*

Design a stack that supports getMin() in O(1) time

Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), peek() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must have a time complexity of O(1). 

Example: 

Input: queries = [push(2), push(3), peek(), pop(), getMin(), push(1), getMin()]
Output: [3, 2, 1]
Explanation:
push(2): Stack is [2]
push(3): Stack is [2, 3]
peek(): Top element is 3
pop(): Removes 3, stack is [2]
getMin(): Minimum element is 2
push(1): Stack is [2, 1]
getMin(): Minimum element is 1
*/

/*
[Approach 1] With Extra Space - O(1) Time and O(n) Space
Create a class node that has two variables Val and min. Val will store the actual value that we are going to insert in the stack, 
whereas min will store the min value so far seen up to that node.

Below is the implementation of the above approach:
*/
// C++ program to implement a stack that supports
// all operations in O(1) time and O(n) extra space.

#include <iostream>
#include <stack>
using namespace std;

// A user defined stack that supports getMin() in
// addition to push(), pop() and peek()
class SpecialStack {
private:
    stack<pair<int, int> > s;

public:
    SpecialStack() {
        
    }
    
    // Add an element to the top of Stack
    void push(int x) {
        int newMin = s.empty() ? x : min(x, s.top().second);

        // we push the pair of given element and newMin into stack
        s.push({ x, newMin });
    }
    
    // Remove the top element from the Stack
    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }
    
    // Returns top element of the Stack
    int peek() {
        if (s.empty()) {
            return -1;
        }

        int top = s.top().first;
        return top;
    }
    
    // Finds minimum element of Stack
    int getMin() {
        if (s.empty()) {
            return -1;
        }
        
        int mn = s.top().second;
        return mn;
    }
};

int main() {
    SpecialStack ss;
    
    // Function calls
    ss.push(2);
    ss.push(3);
    cout << ss.peek() << " ";
    ss.pop();
    cout << ss.getMin() << " ";
    ss.push(1);
    cout << ss.getMin() << " ";
}

// Output: 3 2 1    

/*
[Approach 2] Without Extra Space- O(1) Time and O(1) Space
The idea is to use a variable minEle to track the minimum element in the stack. Instead of storing the actual value of minEle in the stack, we store a modified value when pushing an element smaller than minEle. This allows retrieving the previous minimum in O(1) time and space.

Operations

Push(x)
If the stack is empty, push x and set minEle = x.
If x >= minEle, push x normally.
If x < minEle, push 2*x - minEle and update minEle = x (this encodes the previous min).
Pop()
Remove the top element.
If the removed element is >= minEle, no change in minEle.
If the removed element is < minEle, update minEle = 2*minEle - top (decoding the previous min).
Peek()
Returns minEle if the top is modified (encoded) or top otherwise.
getMin()
Returns minEle, the current minimum in O(1) time.
*/

// C++ program to implement a stack that supports
// all operations in O(1) time and O(1) extra space.

#include <iostream>
#include <stack>
using namespace std;

// A user defined stack that supports getMin() in
// addition to push(), pop() and peek()
class SpecialStack {
  private:
    stack<int> s;
    int minEle;
    
  public:
    SpecialStack() {
        minEle = -1;
    }
    
    // Add an element to the top of Stack
    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        }

        // If new number is less than minEle
        else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        }

        else {
            s.push(x);
        }
    }
    
    // Remove the top element from the Stack
    void pop() {
        if (s.empty()) {
            return ;
        }
        
        int top = s.top();
        s.pop();
        
        // Minimum will change, if the minimum element
        // of the stack is being removed.
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    
    // Returns top element of the Stack
    int peek() {
        if (s.empty()) {
            return -1;
        }

        int top = s.top();

        // If minEle > top means minEle stores value of top.
        return (minEle > top) ? minEle : top;
    }
    
    // Finds minimum element of Stack
    int getMin() {
        if (s.empty())
            return -1;

        // variable minEle stores the minimum element
        // in the stack.
        return minEle;
    }
};

int main() {
    SpecialStack ss;
    
    // Function calls
    ss.push(2);
    ss.push(3);
    cout << ss.peek() << " ";
    ss.pop();
    cout << ss.getMin() << " ";
    ss.push(1);
    cout << ss.getMin() << " ";
}

// Output: 3 2 1
