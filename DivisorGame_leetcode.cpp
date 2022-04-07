#include<iostream>
using namespace std;
/*
bool divisorGame(int n,int k=1)
{
    if(n<=1)
    {
        if(k==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool out=false;
    for(int i=1;i<n;i++)
    {
        bool check=false;
        if(n%i==0)
        {
            if(k==0)
            {
                k=1;
            }
            else if(k==1)
            {
                k=0;
            }
            bool ans=divisorGame(n-i,k);
            if(ans)
            {
                check=true;
                out=true;
            }
        }
        if(check)
        {
            break;
        }
    }
    return out;

}
*/
bool divisorGame(int n)
{
    bool *ans=new bool[n+1];
    ans[0]=false;
    ans[1]=false;
    for(int i=2;i<=n;i++)
    {
        bool check=true;
        int k=i-1;
        while(k>0)
        {
            if(i%k==0)
            {
                check=check&&ans[i-k];
            }
            k--;
        }
        ans[i]=!check;
    }
    return ans[n];
}
int main()
{
    int n;
    cin>>n;
    if(divisorGame(n))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

}
