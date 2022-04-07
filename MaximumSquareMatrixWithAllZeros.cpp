#include <iostream>
using namespace std;
/*
int maxSqmatrix(int **arr,int i,int j)
{
    if(i<0 || j<0)
    {
        return 0;
    }
    if(i==0 || j==0)
    {
        //cout<<"returned"<<i<<" "<<j<<endl;
        return 1;
    }

    int ans1=0,ans2=0,ans3=0;

    if(i-1>=0 && arr[i-1][j]!=1)
    {
        //cout<<arr[i-1][j]<<" not equals to 1"<<endl;
        ans1=maxSqmatrix(arr,i-1,j);
    }
    else
    {
        return 1;
    }

    if(j-1>=0 && arr[i][j-1]!=1)
    {
        //cout<<arr[i][j-1]<<" not equals to 1"<<endl;
        ans2=maxSqmatrix(arr,i,j-1);
    }
    else
    {
        return 1;
    }
    if(i-1>=0 && j-1>=0 && arr[i-1][j-1]!=1)
    {
        //cout<<arr[i-1][j-1]<<" not equals to 1"<<endl;
        ans3=maxSqmatrix(arr,i-1,j-1);
    }
    else
    {
        return 1;
    }
    //cout<<"ans1 is :"<<ans1<<" ans 2 is :"<<ans2<<" ans3 is :"<<ans3<<endl;
    return 1+min(ans1,min(ans2,ans3));

}
*/

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
	int **dp=new int*[n];
	for(int i=0;i<n;i++)
    {
        dp[i]=new int[m];
    }
    int maxi=0;
    //filling first row
    for(int i=0;i<m;i++)
    {
        if(arr[0][i]==1)
        {
            dp[0][i]=0;
        }
        else
        {
            dp[0][i]=1;
        }
        if(maxi<dp[0][i])
        {
            maxi=dp[0][i];
        }
    }
    //filling first column
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==1)
        {
            dp[i][0]=0;
        }
        else
        {
            dp[i][0]=1;
        }
        if(maxi<dp[i][0])
        {
            maxi=dp[i][0];
        }
    }

    //dp[i][j] means max square submatrix ends at dp[i][j] position
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            if(maxi<dp[i][j])
            {
                maxi=dp[i][j];
            }
        }
    }
    return maxi;

}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];

	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
	//cout<<maxSqmatrix(arr,n-1,m-1)<<endl;


	delete[] arr;

	return 0;
}
