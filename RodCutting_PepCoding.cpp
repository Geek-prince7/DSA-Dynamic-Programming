#include<iostream>
using namespace std;
int rodcut(int *arr,int n)
{
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=arr[0];
    for(int i=2;i<=n;i++)
    {
        int maxi=0;
        int j=i-1;
        while(j>=0)
        {
            int k=i-1-j;
            if(dp[k]+arr[j]>maxi)
            {
                maxi=dp[k]+arr[j];
            }

            j--;
        }
        dp[i]=maxi;
    }
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<"  ";
    }
    cout<<endl;
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"max profit in rod cutting is :"<<rodcut(arr,n);
}
