#include <bits/stdc++.h>
using namespace std;

//#include "solution.h"
/*
//brute force
int minCostPath(int **input, int m, int n)
{
	//Write your code here

    if(m==1 && n==1)
    {
        return input[0][0];
    }
    if(m==0 || n==0)
    {
        return INT_MAX;
    }
    int **arr1=input+1;



    int ans1=minCostPath(arr1,m,n-1);
    int **arr2=new int *[n];
    for (int i = 0; i < n; i++)
	{
		arr2[i] = new int[m-1];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			arr2[i][j-1]=input[i][j];
			//cout<<arr2[i][j-1]<<" ";
		}
		//cout<<endl;
	}
	//cout<<endl;
	int ans2=minCostPath(arr2,m-1,n);


	int **arr3=new int *[n-1];
    for (int i = 0; i < n-1; i++)
	{
		arr3[i] = new int[m-1];
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			arr3[i][j]=input[i+1][j+1];
			//cout<<arr3[i][j]<<" ";
		}
		//cout<<endl;
	}
	//cout<<endl;
	int ans3=minCostPath(arr3,m-1,n-1);
	return input[0][0]+min(ans1,min(ans2,ans3));



}
*/






/*
//memoization
int Helper(int **input, int m, int n,int **value,int i,int j)
{
	//Write your code here

    if(m==1 && n==1)
    {
        return input[0][0];
    }
    if(m==0 || n==0)
    {
        return INT_MAX;
    }
    if(value[i][j]!=INT_MAX)
    {
        return value[i][j];
    }
    int **arr1=input+1;



    int ans1=Helper(arr1,m,n-1,value,i+1,j);
    int **arr2=new int *[n];
    for (int i = 0; i < n; i++)
	{
		arr2[i] = new int[m-1];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			arr2[i][j-1]=input[i][j];
			//cout<<arr2[i][j-1]<<" ";
		}
		//cout<<endl;
	}
	//cout<<endl;
	int ans2=Helper(arr2,m-1,n,value,i,j+1);


	int **arr3=new int *[n-1];
    for (int i = 0; i < n-1; i++)
	{
		arr3[i] = new int[m-1];
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			arr3[i][j]=input[i+1][j+1];
			//cout<<arr3[i][j]<<" ";
		}
		//cout<<endl;
	}
	//cout<<endl;
	int ans3=Helper(arr3,m-1,n-1,value,i+1,j+1);
	value[i][j]=input[0][0]+min(ans1,min(ans2,ans3));
	return value[i][j];



}
*/


/*
//memoization
int Helper(int **input, int m, int n,int **value,int i,int j)
{
	//base case
	if(j==m-1 && i==n-1)
    {
        return input[i][j];
    }
    if(j>=m || i>=n)
    {
        return INT_MAX;
    }
    //check if already exist
    if(value[i][j]!=INT_MAX)
    {
        return value[i][j];
    }
    //recursion
    int ans1=Helper(input,m,n,value,i+1,j);
    int ans2=Helper(input,m,n,value,i,j+1);
    int ans3=Helper(input,m,n,value,i+1,j+1);
    //save for future
	value[i][j]=input[i][j]+min(ans1,min(ans2,ans3));
	//return
	//cout<<" for i and j :"<<i<<" "<<j<<" min is :"<<value[i][j]<<endl;
	return value[i][j];



}
int minCostPath(int **input, int m, int n)
{
    int ** value=new int*[n];
    for (int i = 0; i < n; i++)
	{
		value[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			value[i][j]=INT_MAX;
		}
	}
	return Helper(input,m,n,value,0,0);
}
*/


//DP
int minCostPath(int **input, int m, int n)
{
    int ** value=new int*[n];
    for (int i = 0; i < n; i++)
	{
		value[i] = new int[m];
	}
	value[n-1][m-1]=input[n-1][m-1];
	for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==n-1)
            {
                continue;
            }
            int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
            if(i+1<n)
            {
                ans1=value[i+1][j];
            }
            if(j+1<m)
            {
                ans2=value[i][j+1];
            }
            if(i+1<n && j+1<m)
            {
                ans3=value[i+1][j+1];
            }
            value[i][j]=input[i][j]+min(ans1,min(ans2,ans3));
            //cout<<"ans1 2 n 3 are :"<<ans1<<","<<ans2<<","<<ans3<<endl;
            //cout<<"for i and j :"<<i<<" "<<j<<" value is :"<<value[i][j]<<endl;
        }
    }

	return value[0][0];
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, m, n) << endl;
}
