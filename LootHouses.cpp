#include <iostream>
#include<climits>
using namespace std;
//DP
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *ans=new int[n];
	for(int i=0;i<n;i++)
    {
        ans[i]=INT_MIN;
    }
    ans[0]=arr[0];
    ans[1]=arr[1];
    for(int i=2;i<n;i++)
    {
        ans[i]=max((ans[i-2]+arr[i]),ans[i-1]);
    }
    return ans[n-1];

}

/*
//memoization
int maxMoneyLooted(int *arr, int n,int * ans)
{
   //Base case
   if(n<=0)
    {
        return 0;
    }
    //check if ans already exist
    if(ans[n-1]!=INT_MIN)
    {
        return ans[n-1];
    }
    //calc& recursion
    int maxi=0;
    int ans1=maxMoneyLooted(arr+2,n-2,ans);
    int ans2=maxMoneyLooted(arr+1,n-1,ans);
    maxi=max(ans1+arr[0],ans2);
    //saving for future
    ans[n-1]=maxi;



    return maxi;
}


int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *ans=new int[n];
	for(int i=0;i<n;i++)
    {
        ans[i]=INT_MIN;
    }
    return maxMoneyLooted(arr,n,ans);

}
*/



/*
//Brute force
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    if(n<=0)
    {
        return 0;
    }

    int maxi=0;
    int ans1=maxMoneyLooted(arr+2,n-2);
    int ans2=maxMoneyLooted(arr+1,n-1);
    maxi=max(ans1+arr[0],ans2);




    return maxi;
}
*/



int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}
