#include <iostream>
using namespace std;

// Integer power: base^exp
int intPow(int base, int exp) {
    int result = 1;
    while (exp-- > 0)
        result *= base;
    return result;
}

// Count digits
int digits(int n) {
    if (n == 0)
        return 0;
    return 1 + digits(n / 10);
}

// Reverse number using recursion
int reverse(int n) {
    if (n < 10)
        return n;

    int last = n % 10;
    int rem = n / 10;

    return last * intPow(10, digits(rem)) + reverse(rem);
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Reversed number = " << reverse(n);

    return 0;
}