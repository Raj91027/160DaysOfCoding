/*
Find First Node of Loop in Linked List

Given the head of a linked list that may contain a loop. A loop means that the 
last node of the linked list is connected back to a node in the same list. 
The task is to find the Starting node of the loop in the linked list 
if there is no loop in the linked list return -1.
*/

/*
[Naive approach] Using Hashing - O(n) Time and O(n) Space
The idea is to start traversing the Linked List from head node and while 
traversing insert each node into the HashSet. If there is a loop present in the Linked List, 
there will be a node which will be already present in the hash set.

If there is a node which is already present in the HashSet, return the node value which 
represent the starting node of loop.
else, if there is no node which is already present in the HashSet , then return -1.
*/

// C++ program to find starting node 
// of loop using Hasing

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to detect a loop in the linked list and 
// return the node where the cycle starts using HashSet
Node* findFirstNode(Node* head) {
  
      // HashSet to store visited nodes
    unordered_set<Node*> st; 
    
    Node* currNode = head; 
    
    // Traverse the linked list
    while (currNode != nullptr) {
      
        // If the current node is already in the HashSet,
        // then this is the starting node of the loop
        if (st.find(currNode) != st.end()) {
            return currNode;
        }
        
        // If not, add the current node to the HashSet
        st.insert(currNode);
        
        // Move to the next node
        currNode = currNode->next;
    }
    
    // If no loop found, return nullptr
    return nullptr;
}

int main() {
  
    // Create a linked list: 10 -> 15 -> 4 -> 20
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);

    head->next->next->next->next = head;

    Node* loopNode = findFirstNode(head);

    if (loopNode)
        cout << loopNode->data;
    else
        cout << -1;

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*
[Expected Approach] Using Floyd's loop detection algorithm - O(n) Time and O(1) Space
This approach can be divided into two parts:

1. Detect Loop in Linked List using Floyd’s Cycle Detection Algorithm:
This idea is to use Floyd’s Cycle-Finding Algorithm to find a loop in a linked list. 
It uses two pointers slow and fast, fast pointer move two steps ahead and slow will 
move one step ahead at a time.

Follow the steps below to solve the problem:

Traverse linked list using two pointers (slow and fast).
Move one pointer(slow) by one step ahead and another pointer(fast) by two steps ahead.
If these pointers meet at the same node then there is a loop. 
If pointers do not meet then the linked list doesn’t have a loop.


2. Find Starting node of Loop:
After detecting that the loop is present using above algorithm, 
to find the starting node of loop in linked list, we will reset the slow pointer 
to head node and fast pointer will remain at its position. Both slow and fast pointers 
move one step ahead until fast not equals to slow. 
The meeting point will be the Starting node of loop.


*/

// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to detect a loop in the linked list and 
// return the node where the cycle starts using
// Floyd’s Cycle-Finding Algorithm
Node* findFirstNode(Node* head) {
  
    // Initialize two pointers, slow and fast
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the list
    while (fast != nullptr && fast->next != nullptr) {
      
          // Move slow pointer by one step
        slow = slow->next;          
      
          // Move fast pointer by two steps
        fast = fast->next->next;    

        // Detect loop
        if (slow == fast) {
          
            // Move slow to head, keep fast at meeting point
            slow = head;
            
            // Move both one step at a time until they meet
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            // Return the meeting node, which
              // is the start of the loop
            return slow;
        }
    }
    
    // No loop found
    return nullptr;
}

int main() {
  
    // Create a linked list: 10 -> 15 -> 4 -> 20
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);

    head->next->next->next->next = head;

    Node* loopNode = findFirstNode(head);

    if (loopNode)
        cout << loopNode->data;
    else
        cout << -1;

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/


