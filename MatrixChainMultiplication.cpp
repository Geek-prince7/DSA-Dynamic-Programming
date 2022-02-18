#include <iostream>
#include<climits>
using namespace std;

//#include "solution.h"
//memoization
int Helper(int *arr,int si,int ei,int **dp)
{
    if(ei-si<=1)
    {
        return 0;
    }
    if(ei-si==2)
    {
        return arr[si]*arr[si+1]*arr[ei];
    }
    int mini=INT_MAX;
    if(dp[si][ei]!=-1)
    {
        return dp[si][ei];
    }
    for(int k=si+1;k<ei;k++)
    {

        int ans1=Helper(arr,si,k,dp);
        int ans2=Helper(arr,k,ei,dp);
        int calc=arr[si]*arr[k]*arr[ei];
        if(mini>ans1+ans2+calc)
        {
            mini=ans1+ans2+calc;
            dp[si][ei]=mini;
        }

    }
    return dp[si][ei];



}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    return Helper(arr,0,n,dp);
}

/*
//Brute force
int Helper(int *arr,int si,int ei)
{
    if(ei-si<=1)
    {
        return 0;
    }
    if(ei-si==2)
    {
        return arr[si]*arr[si+1]*arr[ei];
    }
    int mini=INT_MAX;
    for(int k=si+1;k<ei;k++)
    {
        int ans1=Helper(arr,si,k);
        int ans2=Helper(arr,k,ei);
        int calc=arr[si]*arr[k]*arr[ei];
        if(mini>ans1+ans2+calc)
        {
            mini=ans1+ans2+calc;
        }

    }
    return mini;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    return Helper(arr,0,n);
}
*/

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
