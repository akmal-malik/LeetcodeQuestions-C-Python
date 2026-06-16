#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return 1;
    }
};

int main() {
    vector<int> nums = {2, 2, 7, 2};

    Solution obj;
    int ans = obj.singleNumber(nums);

    cout << "Single Number: " << ans << endl;

    return 0;
}