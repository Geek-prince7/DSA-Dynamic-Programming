#include<iostream>
using namespace std;
int getMaximumGenerated(int n)
{
    int* ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    int max=1;
    //ans[2]=1;
    for(int i=2;i<=n;i++)
    {
        if(i/2==i-i/2)
        {
            ans[i]=ans[i/2];
        }
        else
        {
            ans[i]=ans[i/2]+ans[i-i/2];
        }
        if(max<ans[i])
        {
            max=ans[i];
        }
    }
    return max;
}
int main()
{
    int n;
    cin>>n;
    cout<<getMaximumGenerated(n);

}
