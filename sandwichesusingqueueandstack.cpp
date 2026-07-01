#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int students[100];
    int sandwiches[100];

    cout << "Enter students preferences (0 for circular, 1 for square):\n";
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    cout << "Enter sandwiches stack (top to bottom):\n";
    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    // Queue for students
    queue<int> q;

    // Stack for sandwiches
    stack<int> st;

    // Push students into queue
    for (int i = 0; i < n; i++) {
        q.push(students[i]);
    }

    // Push sandwiches into stack
    // Reverse order because first sandwich is the top
    for (int i = n - 1; i >= 0; i--) {
        st.push(sandwiches[i]);
    }

    int rotation = 0;

    while (!q.empty() && rotation < q.size()) {

        if (q.front() == st.top()) {
            q.pop();
            st.pop();
            rotation = 0;
        }
        else {
            q.push(q.front());
            q.pop();
            rotation++;
        }
    }

    cout << "\nNumber of students unable to eat: " << q.size() << endl;

    return 0;
}