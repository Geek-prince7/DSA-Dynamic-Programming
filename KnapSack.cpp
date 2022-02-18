#include <iostream>
#include<climits>
using namespace std;
//DP
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **ans=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        ans[i]=new int[maxWeight+1];
    }
    //ans[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        ans[i][0]=0;
    }
    for(int i=0;i<=maxWeight;i++)
    {
        ans[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxWeight;j++)
        {
            int ans1=INT_MIN,ans2=INT_MIN;
            if(weights[n-i]>j)
            {
                ans1=ans[i-1][j];
                ans[i][j]=ans1;
                continue;
            }
            else
            {
                ans1=ans[i-1][j];
                ans2=ans[i-1][j-weights[n-i]]+values[n-i];
                ans[i][j]=max(ans1,ans2);
            }
        }

    }
            return ans[n][maxWeight];
}
/*
//memoization
int knapsack(int *weights, int *values, int n, int maxWeight,int **ans)
{
    if(n==0 || maxWeight==0)
    {
        return 0;
    }
    if(ans[n][maxWeight]!=INT_MIN)
    {
        return ans[n][maxWeight];
    }
    int ans1,ans2=INT_MIN;
    if(weights[0]>maxWeight)
    {
        ans1=knapsack(weights+1,values+1,n-1,maxWeight,ans);
    }
    else
    {
        ans1=knapsack(weights+1,values+1,n-1,maxWeight,ans);
        ans2=values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0],ans);
    }
    ans[n][maxWeight]=max(ans1,ans2);
    return max(ans1,ans2);


}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **ans=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        ans[i]=new int[maxWeight+1];
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<maxWeight+1;j++)
        {
            ans[i][j]=INT_MIN;
        }
    }
    return knapsack(weights,values,n,maxWeight,ans);
}

*/


/*


//Brute force
int Helper(int *weights, int *values, int n, int maxWeight,int tw,int tv)
{
    if(n==0)
    {
        return tv;
    }
    if(tw>maxWeight)
    {
        return INT_MIN;
    }
    int ans1=Helper(weights+1,values+1,n-1,maxWeight,tw,tv);
    int ans2=INT_MIN;
    if(maxWeight>tw+weights[0])
    {
        tw+=weights[0];
        tv+=values[0];
        ans2=Helper(weights+1,values+1,n-1,maxWeight,tw,tv);
    }
    return max(ans1,ans2);
}
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	int tw=0;
	int tv=0;
	return Helper(weights,values,n,maxWeight,tw,tv);
}
*/

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}
