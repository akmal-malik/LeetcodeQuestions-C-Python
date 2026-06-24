// C++ program to delete middle of a linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

// Function to delete middle node from linked list.
Node* deleteMid(Node* head) {
  if (head == NULL || head -> next == NULL){
    delete head;
    head = NULL;
    return NULL;
  }
  
  Node* slow = head;
  Node* fast = head;
  Node* prev = NULL;
  
  while(fast != NULL && fast -> next != NULL){
    prev = slow;
    slow = slow -> next;
    fast = fast -> next -> next;
  } 
  prev -> next = slow -> next;
  delete slow;
  return head;
}







void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create a static hardcoded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5.
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);

    // Delete the middle node.
    head = deleteMid(head);

    cout << "Linked List after deleting the middle node: ";
    printList(head);

    return 0;
}