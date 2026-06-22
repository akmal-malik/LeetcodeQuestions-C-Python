 #include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            next = nullptr;
        }
};

int main(){
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);

    while (head != nullptr) {
        cout << head -> data << " ";
        head = head -> next;
    }
}