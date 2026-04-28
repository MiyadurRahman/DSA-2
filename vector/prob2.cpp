// prob-2 check if every string of an array has started with the same 4 chars

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<string> vs;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        vs.push_back(temp);
    }
    string s;
    s=vs[0].substr(0,4);
    for(int i=1;i<n;i++)
    {
        if(vs[i].substr(0,4)!=s)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;


}


