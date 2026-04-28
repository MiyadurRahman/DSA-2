// You are to create a dictionary.
// check if the 4th word of the dictionary is
// palindrome

// abcba


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
    sort(vs.begin(),vs.end());
    string rev=vs[3];
    reverse(rev.begin(),rev.end());
    if(vs[3]==rev)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

