#include<iostream>
#include<vector>
using namespace std;
int maxprofit(vector<int> &price)
{


    int n=price.size();
    int maxprof=0;
    int mini=price[0],maxi=price[0];
    int *ans=new int[n];
    ans[0]=0;
    for(int i=1;i<n;i++)
    {
        if(price[i]<mini)
        {
            mini=price[i];
            maxi=price[i];
            ans[i]=ans[i-1];
        }
        else if(price[i]>maxi)
        {
            maxi=price[i];
            ans[i]=price[i]-mini;
        }
        else
        {
            ans[i]=ans[i-1];
        }
        if(maxprof<ans[i])
        {
            maxprof=ans[i];
        }
    }



    return maxprof;

}
int main()
{
    vector<int> price;
    while(1)
    {
        int n;
        cin>>n;
        if(n==-222)
        {
            break;
        }
        price.push_back(n);
    }
    cout<<maxprofit(price);

}
