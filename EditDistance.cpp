#include<bits/stdc++.h>
using namespace std;
/*
//Brute force
int editDistance(string s1,string s2)
{
    if(s1.size()==0 && s2.size()==0)
    {
        return 0;
    }
    if(s1.size()==0 || s2.size()==0)
    {
        if(s1.size()!=0)
       {
    		return s1.size();
       }
       else
       {
           return s2.size();
       }
    }
    int op=0;
    int ans=0;
    if(s1[0]==s2[0])
    {
        ans=editDistance(s1.substr(1),s2.substr(1));
    }

    else
    {
        op=1;
        int x=INT_MAX,y=INT_MAX,z=INT_MAX;

            x=editDistance(s1.substr(1),s2);


            y=editDistance(s1,s2.substr(1));


            z=editDistance(s1.substr(1),s2.substr(1));

        ans=min(x,min(y,z));
    }
    return op+ans;
}
*/



//memoization
/*
int editDistance(string s1,string s2,int **ans)
{
    if(s1.size()==0 && s2.size()==0)
    {
        return 0;
    }
    if(s1.size()==0 || s2.size()==0)
    {
        if(s1.size()!=0)
       {
    		return s1.size();
       }
       else
       {
           return s2.size();
       }
    }
    int i=s1.size();
    int j=s2.size();
    if(ans[i][j]!=-1)
    {
        return ans[i][j];
    }
    int op=0;
    int out=0;
    if(s1[0]==s2[0])
    {
        out=editDistance(s1.substr(1),s2.substr(1),ans);
    }

    else
    {
        op=1;
        int x=INT_MAX,y=INT_MAX,z=INT_MAX;

            x=editDistance(s1.substr(1),s2,ans);


            y=editDistance(s1,s2.substr(1),ans);


            z=editDistance(s1.substr(1),s2.substr(1),ans);

        out=min(x,min(y,z));
    }
    ans[i][j]=out+op;
    return ans[i][j];

}
int editDistance(string s1,string s2)
{
    int n=s1.size();
    int m=s2.size();
    int **ans=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=new int[m+1];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            ans[i][j]=-1;
        }
    }
    return editDistance(s1,s2,ans);


}
*/
int editDistance(string s1,string s2)
{
    int x=s1.size();
    int y=s2.size();
    int **ans=new int*[x+1];
    for(int i=0;i<=x;i++)
    {
        ans[i]=new int[y+1];
    }
    ans[x][y]=0;
    for(int i=x;i>=0;i--)
    {
        for(int j=y;j>=0;j--)
        {
            if(i==x &&j==y)
            {
                continue;
            }

            int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
            if(i+1<=x)
            {
                ans1=ans[i+1][j];
            }
            if(j+1<=y)
            {
                ans2=ans[i][j+1];
            }
            if(i+1<=x && j+1<=y)
            {
                ans3=ans[i+1][j+1];
            }
            string a=s1.substr(i);
            string b=s2.substr(j);
            if(a[0]==b[0])
            {

                if(ans3!=-1)
                {
                    ans[i][j]=ans3;
                }
                else
                {
                    ans[i][j]=0;
                }
                continue;
            }
            ans[i][j]=1+min(ans1,min(ans2,ans3));

        }
    }
    return ans[0][0];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1,s2)<<endl;
}
