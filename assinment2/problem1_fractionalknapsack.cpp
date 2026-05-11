#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double F;

bool comparefunc(pair<int, int> &a, pair<int, int> &b)
{
    if ((1.0 * a.first / a.second - F) > (1.0 * b.first / b.second - F))
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int N;
    double capacity;
    cin >> N >> capacity >> F;

    vector<pair<int, int>> items;

    for (int i = 0; i < N; i++)
    {
        int value, weight;
        cin >> value >> weight;
        items.push_back({value, weight});
    }

    sort(items.begin(), items.end(), comparefunc);

    double total_profit = 0;

    for (int i = 0; i < N; i++)
    {
        if (capacity == 0)
        {
            break;
        }

        double profit_per_unit = (1.0 * items[i].first / items[i].second) - F;

        if (profit_per_unit <= 0)
            break;

        if (capacity >= items[i].second)
        {
            capacity -= items[i].second;
            total_profit += items[i].first - F * items[i].second;
        }
        else
        {
            double fraction = capacity / items[i].second;
            total_profit += fraction * (items[i].first - F * items[i].second);
            capacity = 0;
        }
    }

    cout << fixed << setprecision(2) << total_profit << endl;
}