/*
Detect and Remove Loop in Linked List

Given the head of a linked list that may contain a loop.  
A loop means that the last node of the linked list is connected back to a node in the same list. 
The task is to remove the loop from the linked list (if it exists).
*/

/*
[Naive Approach] Detect and Remove Loop using Hashing - O(n) Time and O(n) Space
The idea is to start traversing the Linked List from head node and while traversing insert each node into the HashSet. 
Also, maintain a prev pointer which points to the previous node of the current node. 
If there is a loop present in the Linked List, there will be a node which will be already present in the hash set.

If there is a node which is already present in the HashSet, then update the next pointer of prev to NULL to remove the loop from the linked list.
else, if there is no node which is already present in the HashSet , then there is no loop in the linked list.
*/

//Driver Code Starts{
// C++ code to detect and remove loop in
// linked list using hashing

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
//Driver Code Ends }


// Function to detect and remove loop in
// a linked list
void removeLoop(Node *head) {

    // hash set to hash addresses of
    // the linked list nodes
    unordered_set<Node *> st;

    // pointer to prev node
    Node *prev = nullptr;
    while (head != nullptr) {

        // if node not present in the map,
        // insert it in the map
        if (st.find(head) == st.end()) {
            st.insert(head);
            prev = head;
            head = head->next;
        }
      
        // if present, it is a cycle, make
        // last node's next pointer NULL
        else {
            prev->next = nullptr;
            break;
        }
    }
}


//Driver Code Starts{
int main() {
  
    // Create a hard-coded linked list: 
    // 1 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    // Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}
//Driver Code Ends }

/*
Output:
1 3 4
*/

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*
[Efficient Approach] Using Floyd's Cycle Detection Algorithm - O(n) Time and O(1) Space
This approach can be divided into two parts:

1. Detect Loop in Linked List using Floyd's Cycle Detection Algorithm:
Use two pointers, slow and fast and initialize them with the head of the linked list.
Move the fast pointer forward by two nodes and move the slow pointer forward by one node.
If the slow and fast pointer points to the same node, loop is found.
Else if the fast pointer reaches NULL, then no loop is found.
Else repeat the above steps till we reach the end of the linked list or a loop is found.


2. Remove Loop in Linked List (if any):
The idea is similar to finding the starting node of Loop in a Linked List. 
For this, we will point the slow pointer to head node and fast pointer will remain at its position. 
Both slow and fast pointers move one step ahead until fast->next is not equals to slow->next. 
When slow->next equals to fast->next we can easily point fast->next to NULL to remove the loop.
*/

//Driver Code Starts{
// C++ program Using Floyd's Cycle Detection Algorithm

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
//Driver Code Ends }


// Function to detect and remove loop in a linked list that
// may contain loop
void removeLoop(Node *head) {
  
    // If list is empty or has only one node without loop
    if (head == nullptr || head->next ==nullptr)
        return;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // since fast->next is the looping point 
        fast->next = nullptr;
    }
}


//Driver Code Starts{
int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
    // Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}
//Driver Code Ends }

/*
Output:
1 3 4
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
