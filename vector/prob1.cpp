// prob-1: find the 3rd maximum of an integer array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
    vector<int>v;
    //v.push_back(50);
    //v.push_back(60);
    //v.push_back(20);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    /*for(int x:v)
        cout<<x<<" ";
    cout<<endl;*/
    //v.begin() and v.end() returns an iterator/advanced pointer
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    if(v.size()<3)
        cout<<" vector size is less than 3"<<endl;
    else{
        cout<<v.at(2)<<endl;
    }

    for(auto x:v)  // when the data type is not sure
        cout<<x<<" ";
    cout<<endl;

}




