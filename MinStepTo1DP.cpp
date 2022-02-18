#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int countMinStepsToOne(int n)
{
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=0;
    for(int i=2;i<=n;i++)
    {
        //cout<<"iteration "<<i<<endl;
        int ans1=INT_MAX;
        int ans2=INT_MAX;
        //cout<<"initial value of ans1,ans2 : "<<ans1<<" "<<ans2<<endl;
        if(i%3==0)
        {
         ans2=ans[i/3];
         //cout<<" n divisible by 3"<<endl;
        }
        if(i%2==0)
        {
         ans1=ans[i/2];
         //cout<<"n divisible by 2"<<endl;
        }

        //cout<<"ans[i-1],ans1,ans2 are : "<<ans[i-1]<<" "<<ans1<<" "<<ans2<<endl;
        ans[i]=1+min(ans[i-1],min(ans1,ans2));
        //cout<<"at index "<< i<<" :"<<ans[i]<<endl;
    }
    return ans[n];
}


int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}
