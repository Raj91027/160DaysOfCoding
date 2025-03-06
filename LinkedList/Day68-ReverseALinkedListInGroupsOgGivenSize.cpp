//Reverse a Linked List in groups of given size (Iterative Approach)

/*
Given a Singly linked list containing n nodes. The task is to reverse every group of k nodes in the list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed.


To reverse a linked list in groups of size k, the goal is to traverse the list in segments of k nodes 
and reverse each group individually. After reversing each group, we connect it to the previous group by updating the tail pointer. 
This process continues until the entire list is traversed, and we return the new head of the reversed list.

Follow the steps below to solve the problem:

Initialize pointers:
Set curr to the head of the list to start traversing.
Set newHead to NULL to track the new head after the first group reversal.
Set tail to NULL to connect the previous group to the current reversed group.
Traverse the list in groups of k:
For each group of k nodes, set groupHead to curr.
Reverse the nodes in the group by updating the next pointers, using prev and nextNode.
Connect the reversed group to the previous one:
After reversing, if tail is not nullptr, connect the previous group’s end to the current reversed group’s head.
Update tail to point to the last node of the current group.
Repeat the process until all nodes in the list are processed, and return newHead, which points to the head of the fully reversed list
*/

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

Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr) {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *nextNode = nullptr;
        int count = 0;

        // Reverse the nodes in the current group
        while (curr != nullptr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // If newHead is null, set it to the
          // last node of the first group
        if (newHead == nullptr) {
            newHead = prev;
        }

        // Connect the previous group to the 
          // current reversed group
        if (tail != nullptr) {
            tail->next = prev;
        }

        // Move tail to the end of the reversed group
        tail = groupHead;
    }

    return newHead;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    
    // Creating a sample singly linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = reverseKGroup(head, 3);
    printList(head);

    return 0;
}

