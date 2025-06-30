/*
    Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

    Note: We can either take the item as a whole or break it into smaller units.

    Example:

    Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

    Output: 240.00

    Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for setprecision

using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort by value/weight ratio in descending order
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto& item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            totalValue += item.value;
            W -= item.weight;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }

    return totalValue;
}

int main() {
    int N = 3, W = 50;
    vector<int> values = {100, 60, 120};
    vector<int> weights = {20, 10, 30};

    vector<Item> items;
    for (int i = 0; i < N; i++) {
        items.emplace_back(values[i], weights[i]);
    }

    double maxValue = fractionalKnapsack(W, items);
    cout << fixed << setprecision(2);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

// Time: O(N log N) — for sorting.
// Space: O(1) extra (besides input).