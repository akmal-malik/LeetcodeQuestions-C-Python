#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    // Find first character with frequency 1
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = firstUniqChar(s);

    cout << "Index of first unique character: " << result << endl;

    return 0;
}