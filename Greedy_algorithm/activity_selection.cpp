#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>&a,pair<int,int>&b)
{
    if(a.second<b.second)
    {
        return true; /// do not want to swap
    }
    else
        return false; /// want to swap

}

int main()
{
    ///INPUT
    int n; // no of activities
    cin>>n;
    vector<pair<int,int>>ac;

    for(int i=0;i<n;i++)
    {
        int start, end;
        cin>>start>>end;
        ac.push_back({start,end});

    }
    ///SORT
    sort(ac.begin(),ac.end(),compare);
    cout<<"after sorting-->"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ac[i].first<<" "<<ac[i].second<<endl;
    }

    ///CHOOSE
    int current_finish_time=-1,count=0;
    for(int i=0;i<n;i++)
    {
        /// if the next work's start time is more than
        /// current work's finish time
        if(ac[i].first>current_finish_time)
        {
            count++;
            current_finish_time=ac[i].second;

        }
    }
    cout<<count<<endl;


}
