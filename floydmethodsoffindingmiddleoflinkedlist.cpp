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

// Insert at Tail
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

// Print List
void printList(Node* head) {

    if (head == NULL) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}


Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;


    while ( curr != NULL){
        Node* nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}


int findLengthofLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 0;
            Node* temp = slow;

            while (true) {
                count++;
                temp = temp->next;

                if (temp == slow)
                    break;
            }

            return count;
        }
    }

    return 0; 
}

// Find Middle Node (returns second middle for even nodes)
Node* findMiddle(Node* head) {

    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* findMiddle(Node* head) {
    if (head == NULL)
        return NULL;

    int count = 0;
    Node* temp = head;

    // Count total nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Move to middle node
    temp = head;
    for (int i = 0; i < count / 2; i++) {
        temp = temp->next;
    }

    return temp;
}

// Insert After Middle
void insertAfterMiddle(Node* &head, int data) {

    if (head == NULL) {
        head = new Node(data);
        return;
    }

    Node* middle = findMiddle(head);

    Node* newNode = new Node(data);

    newNode->next = middle->next;
    middle->next = newNode;
}

void DeleteMiddleNode(Node* head){
    if (head == NULL || head -> next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast -> next != NULL){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    prev -> next = slow -> next;
    delete slow;
}
// Delete After Middle
void deleteAfterMiddle(Node* &head) {

    if (head == NULL)
        return;

    Node* middle = findMiddle(head);

    // Middle ke baad node hi nahi hai
    if (middle == NULL || middle->next == NULL)
        return;

    Node* nodeToDelete = middle->next;

    middle->next = nodeToDelete->next;

    delete nodeToDelete;
}

// Insert After Given Node
void insertAfterNode(Node* node, int data) {

    if (node == NULL)
        return;

    Node* newNode = new Node(data);

    newNode->next = node->next;
    node->next = newNode;
}

// Delete After Given Node
void deleteAfterNode(Node* node) {

    if (node == NULL || node->next == NULL)
        return;

    Node* nodeToDelete = node->next;

    node->next = nodeToDelete->next;

    delete nodeToDelete;
}

int main() {

    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    cout << "Original List:\n";
    printList(head);

    // Find Middle
    Node* middle = findMiddle(head);

    if (middle != NULL)
        cout << "Middle Node: " << middle->data << endl;

    // Insert After Middle
    insertAfterMiddle(head, 99);

    cout << "\nAfter Insert After Middle:\n";
    printList(head);

    // Delete After Middle
    deleteAfterMiddle(head);

    cout << "\nAfter Delete After Middle:\n";
    printList(head);

    // Given Node = 20
    Node* givenNode = head->next;

    insertAfterNode(givenNode, 25);

    cout << "\nAfter Insert After Node(20):\n";
    printList(head);

    deleteAfterNode(givenNode);

    cout << "\nAfter Delete After Node(20):\n";
    printList(head);

    return 0;
}