/*

Detect Loop or Cycle in Linked List

Given a singly linked list, check if the linked list has a loop (cycle) or not. 
A loop means that the last node of the linked list is connected back to a node in the same list.

[Naive Approach] Using HashSet - O(n) Time and O(n) Space
The idea is to insert the nodes in the Hashset while traversing and whenever 
a node is encountered that is already present in the hashset (which indicates there's a cycle (loop) in the list) then return true. 
If the node is NULL, represents the end of Linked List, return false as there is no loop.
*/

// C++ program to detect loop in a linked list
// using hashset

#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

bool detectLoop(Node* head) {
    unordered_set<Node*>st;
  
    while (head != nullptr) {

        // If this node is already present
        // in hashmap it means there is a cycle
        if (st.find(head) != st.end())
            return true;

        // If we are seeing the node for
        // the first time, insert it in hash
        st.insert(head);

        head = head->next;
    }
    return false;
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
    // Create a loop
    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}


/*

[Expected Approach] Using Floyd's Cycle-Finding Algorithm - O(n) Time and O(1) Space
This idea is to use Floyd's Cycle-Finding Algorithm to find a loop in a linked list. 
It uses two pointers slow and fast, 
fast pointer move two steps ahead and slow will move one step ahead at a time.

Follow the steps below to solve the problem:

Traverse linked list using two pointers.
Move one pointer(slow) by one step ahead and another pointer(fast) by two steps ahead.
If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn't have a loop.
*/

// C++ program to detect loop in a linked list
// using Floyd's Cycle-Finding Algorithm

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

bool detectLoop(Node* head) {
  
    // Fast and slow pointers initially points to the head
    Node *slow = head, *fast = head;

    // Loop that runs while fast and slow pointer are not
    // nullptr and not equal
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // If fast and slow pointer points to the same node,
        // then the cycle is detected
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
    // Create a loop
    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}

/*
Time complexity: O(n), where n is the number of nodes in the Linked List.
Auxiliary Space: O(1). 
*/