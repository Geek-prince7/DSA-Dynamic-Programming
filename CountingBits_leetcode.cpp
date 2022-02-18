#include<iostream>
#include<vector>
using namespace std;
vector<int> count_bits(int n)
{
    /*
    if(n==0)
    {
        vector<int> out;
        out.push_back(0);
    }
    int a=n;
    int count=0;
    while(a>0)
    {
        if(a%2!=0)
        {
            count++;
        }
        a=a/2;

    }
    */
    vector<int> ans;
    ans.push_back(0);
    //ans.push_back(1);
    for(int i=1;i<=n;i++)
    {
        int k=i;
        int count=0;
        while(k>1)
        {
            if(k%2!=0)
            {
                count++;
            }
            k=k/2;
        }
        ans.push_back(1+count);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> ans=count_bits(n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
