#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target) {
    int left = 0;
    long long sum = 0;

    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];

        // Shrink the window if sum becomes greater than target
        while (sum > target && left <= right) {
            sum -= arr[left];
            left++;
        }

        // Target found
        if (sum == target) {
            return {left + 1, right + 1}; // 1-based indexing
        }
    }

    return {-1};
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> ans = subarraySum(arr, target);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "No subarray found\n";
    } else {
        cout << "Subarray found from index "
             << ans[0] << " to " << ans[1] << endl;
    }

    return 0;
}