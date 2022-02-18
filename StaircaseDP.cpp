#include<iostream>
using namespace std;
long staircase(int n)
{
	//Write your code here
	long *ans=new long[n+2];
	ans[0]=0; //for n<0
	ans[1]=1; //for n==0
	ans[2]=1;//for n==1
	for(int i=3;i<=n+1;i++)
    {
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n+1];

    //return staircase(n,ans);




}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
