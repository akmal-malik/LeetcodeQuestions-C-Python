#include <iostream>
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

    int size = n;
    int top = 0;
    int pass = 0;

    while (size > 0) {

        if (pass == size)
            break;

        if (students[0] == sandwiches[top]) {


            for (int i = 0; i < size - 1; i++)
                students[i] = students[i + 1];

            size--;
            top++;
            pass = 0;
        }
        else {


            int temp = students[0];

            for (int i = 0; i < size - 1; i++)
                students[i] = students[i + 1];

            students[size - 1] = temp;

            pass++;
        }
    }

    cout << "\nNumber of students unable to eat: " << size << endl;

    return 0;
}