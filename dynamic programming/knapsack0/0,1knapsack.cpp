#include <iostream>
#include <vector>
using namespace std;
struct item{
    int weight;
    int value;
};
//global variable
int n;// no of items
vector<item>items;
int imp_value=-10000000;//imposible value for maximization problem
//for memoriation
int memo[1000][1000];

//current item--> need to take decision on this (should i take it or not)
//rem_weight --> reamining weight to fill up
//returns the value gained
int solve(int current_item,int rem_weight){
    //base case
if(current_item==n){
    return  0;

}
if(rem_weight<items[current_item].weight){
    return solve(current_item+1,rem_weight);//skipt that item

}
//memorization
if(memo[current_item][rem_weight]!=imp_value)//it was solve before
{
    return memo[current_item][rem_weight];
}
// decision should itake or not
int taken = items[current_item].value + solve(current_item+1,rem_weight-items[current_item].weight);
int not_taken=solve(current_item+1,rem_weight);
int ans=max(taken,not_taken);
//save tthe answer
memo[current_item][rem_weight]=ans;
return ans;



}


int main(){
    cin>>n;
    for (int i=0;i<n;i++)
{
    struct  item it;

    {
        cin>>it.weight>>it.value;
        items.push_back(it);//its stores like that items = [ {10, 50}, {20, 60}, {30, 90} ]
    };
    
}
//knapsack wight;
int rem_weight;
cin>>rem_weight;

//memorization initialization
for(int i=0;i<=n;i++){
    for(int j=0;j<=rem_weight;j++){
  memo[i][j]=imp_value;//that means problem is yet to solve


    }
}
cout<<solve(0,rem_weight)<<endl;







}