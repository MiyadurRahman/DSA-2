#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compareFunc(const pair <int,int>& a,const pair<int,int>& b){
if(a.first < b.first){

    return true;
}
else{
    return false;
}


}
int main (){

vector<pair<int,int>> vp;
int n;
cin>>n;
for(int i=0;i<n;i++){
int temp1,temp2;
cin>>temp1>>temp2;
vp.push_back({temp1,temp2});
}
sort(vp.begin(),vp.end(),compareFunc);
for( auto x: vp){
    cout<<x.first<<"  "<<x.second;
    cout<<endl;
}
}