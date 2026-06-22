#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

Node* findMiddle(Node* head) {

    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps
    }

    return slow;
}

int main() {

    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    cout << "Linked List: ";
    printList(head);

    Node* middle = findMiddle(head);

    cout << "Middle Node: " << middle->data << endl;

    return 0;
}