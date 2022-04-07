#include <bits/stdc++.h>
using namespace std;

/*
int minCount(int n)
{
	//Write your code here
    // if ( sqrt (n) -floor(sqrt(n))==0)  return 1;

      int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    //arr[2]=2;
    //arr[3]=3;

    for(int i=2 ;i<=n ;i++)
    {

        arr[i] = i;

        for (int x = 1; x <= n/2; x++) {
            int temp = x * x;
            if (temp > i)
                break;
            else
                arr[i] = min(arr[i], 1 + arr[i - temp]);
           }
    }
    return arr[n];
}
*/

int minCount(int n)
{
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        ans[i]=INT_MAX;
        for(int j=0;i-j*j>=0;j++)
        {
            ans[i]=min(ans[i],ans[i-j*j]);
        }
        ans[i]+=1;
    }
    return ans[n];
}

//#include "solution.h"

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
