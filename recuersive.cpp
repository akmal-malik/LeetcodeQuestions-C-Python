#include <iostream>
using namespace std;

void recursiveFunction(int n) {
    if (n == 1) {
        return;
    }

    cout << "hello" << endl;

    recursiveFunction(n - 1);
    recursiveFunction(n - 1);
}

int main() {
    recursiveFunction(5);
    return 0;
}