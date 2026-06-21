#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    int maxCost = *max_element(costs.begin(), costs.end());

    vector<int> freq(maxCost + 1, 0);

    for (int cost : costs) {
        freq[cost]++;
    }

    int bars = 0;

    for (int cost = 1; cost <= maxCost; cost++) {
        if (freq[cost] == 0) continue;

        int canBuy = min(freq[cost], coins / cost);

        bars += canBuy;
        coins -= canBuy * cost;
    }

    return bars;
}

int main() {
    int n, coins;

    cout << "Enter number of ice cream bars: ";
    cin >> n;

    vector<int> costs(n);

    cout << "Enter costs: ";
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    cout << "Enter available coins: ";
    cin >> coins;

    cout << "Maximum ice cream bars that can be bought: "
         << maxIceCream(costs, coins) << endl;

    return 0;
}