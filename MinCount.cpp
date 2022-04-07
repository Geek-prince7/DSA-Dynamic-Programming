#include <bits/stdc++.h>
using namespace std;
int minCount(int n)
{
 if(n<=0)
    {
        return 0;
    }
    if(n==1)
    {
        //cout<<"for n="<<n<<" 1 returned to ans"<<endl;
        return 1;
    }
    int ans=INT_MAX;
    int ans2=INT_MAX;
    bool check=false;
    for(int i=n/2;i>0;i--)
    {
        if(i*i<=n)
        {
            //cout<<i*i<<" less than "<<n<<endl;
            ans=minCount(n-(i*i));
            if(i>1)
            {
                ans2=minCount(n-(i-1)*(i-1));
            }
            /*
            if(ans<minans)
            {
                //cout<<"min ans changed"<<minans<<endl;
                minans=ans;
            }
            */
            if(ans!=INT_MAX)
            {
                check=true;
            }
        }
        if(check)
        {
            break;
        }
    }
    return 1+min(ans,ans2);


}
/*
int minCount(int n)
{
	//Write your code here
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        //cout<<"for n="<<n<<" 1 returned to ans"<<endl;
        return 1;
    }
    int minans=INT_MAX;
    for(int i=1;i<=n/2;i++)
    {
        if(i*i<=n)
        {
            //cout<<i*i<<" less than "<<n<<endl;
            int ans=minCount(n-(i*i));
            if(ans<minans)
            {
                //cout<<"min ans changed"<<minans<<endl;
                minans=ans;
            }
        }
    }
    return 1+minans;

}
*/
//#include "solution.h"

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
