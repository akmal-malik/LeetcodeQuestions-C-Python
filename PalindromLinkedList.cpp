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


bool checkPalindrome(Node* head){
    if(head == NULL || head -> next == NULL){
        cout << "Palindrome" << endl;
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    Node* prev = NULL;
    Node* curr = slow;

    while(curr){
        Node* nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }
    

    Node* firstHalf = head;
    Node* secondHalf = prev;


    while(secondHalf){
        if(firstHalf -> data != secondHalf -> data){
            cout << "Not Palindrome" << endl;
            return false;
        }
        firstHalf = firstHalf -> next;
        secondHalf = secondHalf -> next;
    }


}