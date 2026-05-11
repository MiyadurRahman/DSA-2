#include<iostream>
#include<vector>
using namespace std;
//global variable

int n;
vector<int>coins;
int imp_value=10000000;
// for memorization
int memo[1000];//track only the remaining change
//return thenumber of coins needed
int solve(int rem_change){//returns the number of coins needed
    //base case
    if(rem_change==0){

        return 0;
    }
    if(rem_change<0){
        return imp_value;

    }if(memo[rem_change]!=imp_value) /// it was solved before
        return memo[rem_change];


    /// decisions: which coin should I take
    int taken_coins=imp_value;
    for(int i=0; i<coins.size(); i++)
    {
        taken_coins=min(taken_coins,1+solve(rem_change-coins[i]));
    }
    memo[rem_change]=taken_coins;
    return taken_coins;



}

int main(){
cin>>n;
for(int i=0;i<n;i++){

    int coin;
    cin>>coin;
    coins.push_back(coin);

}
//change
int rem_change;
cin>>rem_change;
//memorization initialization
for(int i=0;i<=rem_change;i++){
    memo[i]=imp_value;
}
int ans=solve(rem_change);
    if(ans>=imp_value)
        cout<<"impossible"<<endl;
    else
        cout<<solve(rem_change)<<endl;


}