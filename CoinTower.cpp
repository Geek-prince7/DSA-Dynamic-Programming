#include <iostream>
#include <string>
using namespace std;

//#include "solution.h"
string findWinner(int n, int x, int y)
{
	// Write your code here .
	bool *dp=new bool[n+1];
	dp[0]=false;;
	dp[1]=true;
	for(int i=2;i<=n;i++)
    {
        bool check=true;
        if(i-1>=0)
        {
            check=check&&dp[i-1];
        }
        if(i-x>=0)
        {
            check=check&&dp[i-x];
        }
        if(i-y>=0)
        {
            check=check&&dp[i-y];
        }
        dp[i]=!check;
    }
    if(dp[n])
    {
        return "Beerus";
    }
    return "Whiz";
}
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}
