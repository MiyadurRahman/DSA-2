#include<iostream>
#include<vector>
using namespace std;
struct coin
{
    int count;
    int value;
};

// global variable
int n; // no of coins
vector<coin>coins;
int imp_value=100000000; // impossible value for minimization problem

/// for memoization
int memo[1000][1000];

/// current item --> need to take decision on this.(should I take it or not)
/// rem_weight --> remaining weight to fill up.
/// returns the value gained
int solve(int current_coin,int rem_change)
{
    ///base case
    if(current_coin==n && rem_change>0) // no coin remaining, but change is not done
        return imp_value;
    if(rem_change<0)
        return imp_value;
    if(rem_change==0)
        return 0; // done giving the change


    /// memoization
    if(memo[current_coin][rem_change]!=imp_value) /// it was solved before
        return memo[current_coin][rem_change];


    /// decisions: should I take or not
    int ans=imp_value;
    for(int i=0;i<=coins[current_coin].count;i++)
    {
        /// how much I have given with current coin
        int given=i*coins[current_coin].value;
        ans=min(ans,i+solve(current_coin+1,rem_change-given));
    }
    memo[current_coin][rem_change]=ans;
    return ans;

}


int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        struct coin c;
        cin>>c.count>>c.value;
        coins.push_back(c);

    }

    //change
    int rem_change;
    cin>>rem_change;

    ///memoization initialization
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=rem_change;j++)
        {
            memo[i][j]=imp_value; /// that means the problem is yet to be solved
        }
    }

    cout<<solve(0,rem_change)<<endl;


}