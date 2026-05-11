#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comparefunc(pair<int,int>&a,pair<int,int>&b){
if(1.0*a.first/a.second>1.0*b.first/b.second){
return true;


}
else
return false;


}
int main(){
int n;
cin>>n;
vector<pair<int ,int>>items;
for(int i=0;i<n;i++)
{
int value,weight;
cin>>value>>weight;
items.push_back({value,weight});
}
sort(items.begin(),items.end(),comparefunc);
for(int i=0;i<n;i++)
{
cout<<items[i].first<<"  "<<items[i].second<<endl;

}
int capacity,total_value=0;
cin>>capacity;
for(int i=0 ;i<n;i++){
    if(capacity==0){
        break;
    }
    if(capacity>=items[i].second){//full items chosen
        capacity-=items[i].second;//deduct the price
        total_value+=items[i].first;
    }
    else if(capacity<items[i].second)//chosse the fraction item
    {
        float fraction=1.0*capacity/items[i].second;
        total_value+=1.0*fraction*items[i].first;
    }
}
cout<<total_value<<endl;

}