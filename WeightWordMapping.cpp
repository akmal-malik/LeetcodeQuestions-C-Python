#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    string mapWordsWeights(vector<string> & words, vector<int> &weights){

        string ans;

        for(string &word: words){
            int weight = 0;

            for(char &ch: word){
                weight += weights[ch - 'a'];
            }

            int rem = weight % 26;

            ans += ('z' -  rem);

        }
        return ans;
    }
};

int main() {
    vector<string> words = {"abc", "bcd", "xyz"};
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                           11, 12, 13, 14, 15, 16, 17, 18,
                           19, 20, 21, 22, 23, 24, 25, 26};

    Solution obj;
    string result = obj.mapWordsWeights(words, weights);

    cout << "Mapped String: " << result << endl;

    return 0;
}