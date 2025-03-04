//Reverse a Linked List

/*Given a linked list, the task is to reverse the linked list by changing the links between nodes.

Examples: 

Input: head: 1 -> 2 -> 3 -> 4 -> NULL
Output: head: 4 -> 3 -> 2 -> 1 -> NULL
*/

//
/*
[Expected Approach] Using Iterative Method - O(n) Time and O(1) Space
The idea is to reverse the links of all nodes using three pointers:

prev: pointer to keep track of the previous node
curr: pointer to keep track of the current node
next: pointer to keep track of the next node
Starting from the first node, initialize curr with the head of linked list and next with the next node of curr. 
Update the next pointer of curr with prev. 
Finally, move the three pointer by updating prev with curr and curr with next.

Follow the steps below to solve the problem:

Initialize three pointers prev as NULL, curr as head, and next as NULL.
Iterate through the linked list. In a loop, do the following:
Store the next node, next = curr -> next
Update the next pointer of curr to prev, curr -> next = prev
Update prev as curr and curr as next, prev = curr and curr = next
Finally, return prev as the head of the reversed linked list.
*/

// Iterative C++ program to reverse a linked list

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Given the head of a list, reverse the list and 
// return the head of reversed list
Node *reverseList(Node *head) {

    // Initialize three pointers: curr, prev and next
    Node *curr = head, *prev = nullptr, *next;

    // Traverse all the nodes of Linked List
    while (curr != nullptr) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    // Return the head of reversed linked list
    return prev;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked list:";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);

    return 0;
}

/*
[Alternate Approach - 1] Using Recursion - O(n) Time and O(n) Space
The idea is to reach the last node of the linked list using recursion then start reversing the linked list from the last node.

Follow the steps below to solve the problem:

Divide the list in two parts - first node and rest of the linked list.
Call reverse for the rest of the linked list.
Link the rest linked list to first.
Fix head pointer to NULL.
*/

// Recursive C++ program to reverse a linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Given the head of a list, reverse the list
// and return the head of reversed list
Node *reverseList(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    // reverse the rest of linked list and put
    //  the first element at the end
    Node *rest = reverseList(head->next);

    // Make the current head as last node of
    // remaining linked list
    head->next->next = head;

    // Update next of current head to NULL
    head->next = NULL;

    // Return the reversed linked list
    return rest;
}

void printList(Node *node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked List:";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);

    return 0;
}

/*
[Alternate Approach - 2] Using Stack - O(n) Time and O(n) Space
The idea is to traverse the linked list and push all nodes except the last node into the stack. 
Make the last node as the new head of the reversed linked list. 
Now, start popping the element and append each node to the reversed Linked List. 
Finally, return the head of the reversed linked list.

Follow the steps below to solve the problem:

Push all the nodes(values and address) except the last node in the stack.
Once the nodes are pushed, update the Head pointer to the last node.
Start popping the nodes and push them at the end of the linked list in the same order until the stack is empty.
Update the next pointer of last node in the stack by NULL.



*/

// C++ program to reverse linked list using Stack

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Function to reverse the linked list
Node* reverseList(Node* head) {
      
    // Create a stack to store the nodes
    stack<Node*> s;
  
    Node* temp = head;
  
      // Push all nodes except the last node into stack
    while (temp->next != NULL) {
        s.push(temp);
        temp = temp->next;
    }
      
      // Make the last node as new head of the linked list
    head = temp;
  
      // Pop all the nodes and append to the linked list
    while (!s.empty()) {
          
        // append the top value of stack in list
        temp->next = s.top();
        
          // Pop the value from stack
        s.pop();
        
          // move to the next node in the list
        temp = temp->next;
    }
      
      // Update the next pointer of last node of stack to NULL
    temp->next = NULL;
  
      return head;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {
      
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked List:";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);
  
      return 0;
}

/*

