#include <iostream>
#include <vector>
using namespace std;

struct item
{
    int potency;
    int toxicity;
    int quantity;
};

int n, M;
vector<item> items;

int imp_value = 100000000;
int memo[1000][1000];

int solve(int current_item, int rem_potency)
{

    if (rem_potency == 0)
        return 0;

    if (current_item == n)
        return imp_value;

    if (memo[current_item][rem_potency] !=imp_value)
        return memo[current_item][rem_potency];

    int ans = imp_value;

    for (int k = 0; k <= items[current_item].quantity; k++)
    {
        int total_pot = k * items[current_item].potency;

        if (total_pot > rem_potency)
            break;

        int res = solve(current_item + 1, rem_potency - total_pot);

        if (res != imp_value)
        {
            ans = min(ans, res + k * items[current_item].toxicity);
        }
    }

    memo[current_item][rem_potency] = ans;
    return ans;
}

int main()
{

    cin >> n >> M;

    for (int i = 0; i < n; i++)
    {
        item it;
        cin >> it.potency >> it.toxicity >> it.quantity;
        items.push_back(it);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            memo[i][j] = imp_value;
        }
    }

    int result = solve(0, M);

    if (result == imp_value)
        cout << -1 << endl;
    else
        cout << result << endl;
}