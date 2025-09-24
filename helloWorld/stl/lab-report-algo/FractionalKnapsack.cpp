#include <bits/stdc++.h>
using namespace std;

struct Item
{
    double value, weight;
};

int main()
{
    Item items[3] = {{60, 10}, {100, 20}, {120, 30}};
    int n = 3;
    double W = 50; // knapsack capacity

    // Sort items by value/weight ratio in descending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double r1 = items[i].value / items[i].weight;
            double r2 = items[j].value / items[j].weight;
            if (r1 < r2)
                swap(items[i], items[j]);
        }
    }

    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= W)
        {
            W -= items[i].weight;
            total += items[i].value;
        }
        else
        {
            total += items[i].value * (W / items[i].weight);
            break;
        }
    }

    cout << "Max profit (Fractional Knapsack): " << total << endl;
    return 0;
}
