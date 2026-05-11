// find the count of 3's multiple in an array using divide and conquer
// 6 8 4 0 9 12 14 5 
// ans = 3 

#include <iostream>
#include <vector>
using namespace std;

int multipleCount(vector<int> &v, int start, int end)
{
    // base case=============
    if (start == end) // size 1------
    {
        if(v[start]==0)
        return 0;
        if(v[start]%3==0)
        return 1;
        else
        return 0;
    }
    
    // divide===================
    int mid = (start + end) / 2;
    int count1=multipleCount(v, start, mid);
    int count2=multipleCount(v, mid + 1, end);

    // merge=================
    return count1+count2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int ans=multipleCount(v, 0, n - 1);
    cout<<ans<<endl;
    
}

