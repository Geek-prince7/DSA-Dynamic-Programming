#include <bits/stdc++.h>
using namespace std;
//#include "solution.h"


/*
int countMinStepsToOne(int n)
{
	//Write your code here
	if(n==1)
    {
        return 0;
    }
    int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
    if(n%3==0)
    {
        ans1=countMinStepsToOne(n/3);
    }
    if(n%2==0){
        ans2=countMinStepsToOne(n/2);
    }
    ans3=countMinStepsToOne(n-1);

    return 1+min(ans1,min(ans2,ans3));


}
*/


int Helper(int n,int *ans)
{
    //base case
    if(n<=1)
    {
        return 0;
    }
    if(ans[n-1]!=-1)
    {
        return ans[n-1];
    }
    int ans1=Helper(n-1,ans);
    int ans2=INT_MAX,ans3=INT_MAX;
    if(n%2==0)
    {
        ans2=Helper(n/2,ans);
    }
    if(n%3==0)
    {
        ans3=Helper(n/3,ans);
    }
    ans[n-1]=1+min(ans1,min(ans2,ans3));
    return ans[n-1];
}
int countMinStepsToOne(int n)
{
    int *ans=new int[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=-1;
    }
    return Helper(n,ans);
}


int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}
