// calculate x^n
#include <iostream>
using namespace std;

// 2^4 = (2^2)*(2^2)

int recursiveCal(int x, int n)
{
    // base case --> solve

    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    // recursive case --> divide and merge
    if (n % 2 == 0)
    {
        int smaller = recursiveCal(x, n / 2);
        return smaller * smaller;
    }
    else
    {
        int smaller = recursiveCal(x, (n - 1) / 2);
        return smaller * smaller * x;
    }
}

int calculate(int x, int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++) // O(n)
    {
        ans = ans * x;
    }
    // return the x^n value
    return ans;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << recursiveCal(x, n) << endl;
}
