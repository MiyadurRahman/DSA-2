#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct solve
{
    int startIndex;
    int endIndex;
    int sum;
};

/// this function returns the maximum intersection sum
struct solve mergeStep(vector<int>v, int start, int end)
{

    int mid=(start+end)/2;

    //find out which portion to take from left
    // mid --> start
    int leftMaxSum=-100000, leftMaxIndex=-1,current_sum=0;
    for(int i=mid; i>=start; i--)
    {
        current_sum+=v[i];
        if(current_sum>leftMaxSum)
        {
            leftMaxSum=current_sum;
            leftMaxIndex=i;
        }
    }

    //find out which portion to take from right
    // mid+1 --> end
    int rightMaxSum=-100000, rightMaxIndex=-1;
    current_sum=0;
    for(int i=mid+1; i<=end; i++)
    {
        current_sum+=v[i];
        if(current_sum>rightMaxSum)
        {
            rightMaxSum=current_sum;
            rightMaxIndex=i;
        }
    }

    struct solve s;
    s.startIndex=leftMaxIndex;
    s.endIndex=rightMaxIndex;
    s.sum=leftMaxSum+rightMaxSum;
    return s;


};


// return type: struct solve
struct solve max_sum_subarray(vector<int> v, int start,int end)
{
    ///base case
    if(start==end) // size 1
    {
        struct solve s;
        s.startIndex=start;
        s.endIndex=start;
        s.sum=v[start];
        return s;
    }

    /// divide
    int mid=(start+end)/2;
    struct solve leftSolve=max_sum_subarray(v,start, mid);
    struct solve rightSolve=max_sum_subarray(v,mid+1, end);


    ///merge
    struct solve intersectionSolve=mergeStep(v,start,end);
    //int maxsum=max(leftSolve.sum, max(rightSolve.sum,intersectionSolve.sum));

    ///maxsum store the maximum sum among the three solves
    int maxsum=-100000;
    if(maxsum<leftSolve.sum)
        maxsum=leftSolve.sum;

    if(maxsum<rightSolve.sum)
        maxsum=rightSolve.sum;

    if(maxsum<intersectionSolve.sum)
        maxsum=intersectionSolve.sum;


    if(leftSolve.sum==maxsum)
        return leftSolve;

    if(rightSolve.sum==maxsum)
        return rightSolve;

    if(intersectionSolve.sum==maxsum)
        return intersectionSolve;


};

int main()
{
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    struct solve s=max_sum_subarray(v,0,n-1);
    cout<<s.sum<<endl;





}



