#include <iostream>
using namespace std;

//#include "solution.h"

long staircase(int n,long *ans)
{
    if(n==1 ||n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(ans[n]!=-1)
    {
        return ans[n];
    }
    long ans1=staircase(n-1,ans);
    long ans2=staircase(n-2,ans);
    long ans3=staircase(n-3,ans);
    ans[n]=ans1+ans2+ans3;
    return ans[n];

}
long staircase(int n)
{
	//Write your code here
	long *ans=new long[n+1];
    for(int i=0;i<n+1;i++)
    {
        ans[i]=-1;
    }
    return staircase(n,ans);




}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
