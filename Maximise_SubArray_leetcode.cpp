#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maximise_subarraySum(vector<int> &arr)
{
    int n=arr.size();
    int *ans=new int[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=INT_MIN;

    }
    ans[0]=arr[0];
    int max=ans[0];
    int overallmax=ans[0];
    for(int i=1;i<n;i++)
    {

        if(ans[i-1]<0)
        {
            ans[i]=arr[i];
        }
        else
        {
            ans[i]=ans[i-1]+arr[i];
        }


        if(max<ans[i])
        {
            max=ans[i];
        }

    }
    return max;

}
int main()
{
    vector<int> arr;
    while(1)
    {
        int input;
        cin>>input;
        if(input==-222)
        {
            break;
        }
        arr.push_back(input);
    }
    cout<<maximise_subarraySum(arr);
}
