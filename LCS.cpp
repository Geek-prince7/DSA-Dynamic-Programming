#include<bits/stdc++.h>
#include<string>
using namespace std;


//brute force
//TC -2^n
/*
int LCS(string s1,string s2,string out="")
{
  if(s1.size()==0 ||s2.size()==0)
  {
      return out.size();
  }
  char fc=s1[0];
  //bool check=false;
  int getIndex=-1;
  for(int i=0;i<s2.size();i++)
  {
      if(s2[i]==fc)
      {
          //check=true;
          getIndex=i;
          break;
      }
  }
  int ans1=0;
  if(getIndex!=-1)
  {
    ans1=LCS(s1.substr(1),s2.substr(getIndex),out+s1[0]);
  }
  int ans2=LCS(s1.substr(1),s2,out);
  int x=out.size();
  return max(x,max(ans1,ans2));


}

*/



//memoization



//ans is at s1.size,se.size index
/*
int LCS(string s1,string s2,int** ans)
{
    if(s1.size()==0 ||s2.size()==0)
    {
        return 0;
    }
    int i=s1.size();
    int j=s2.size();
    //check if already exist
    if(ans[i][j]!=-1)
    {
        return ans[i][j];
    }
    int output;
    if(s1[0]==s2[0])
    {
        output=1+LCS(s1.substr(1),s2.substr(1),ans);

    }
    else
    {
        int x=LCS(s1.substr(1),s2,ans);
        int y=LCS(s1,s2.substr(1),ans);
        int z=LCS(s1.substr(1),s2.substr(1),ans);
        output=max(x,max(y,z));
    }
    //save for future
    ans[i][j]=output;
    return ans[i][j];
}
*/
/*
//here ans is at 0,0 index
int LCS(string s1,string s2,int** ans,int i,int j)
{
    if(s1.size()==0 || s2.size()==0)
    {
        return 0;
    }
    // check if already exist
    if(ans[i][j]!=-1)
    {
        return ans[i][j];
    }
    if(s1[0]==s2[0])
    {
        ans[i][j]=1+LCS(s1.substr(1),s2.substr(1),ans,i+1,j+1);
        return ans[i][j];
    }
    else
    {
        int a=LCS(s1.substr(1),s2,ans,i+1,j);
        int b=LCS(s1,s2.substr(1),ans,i,j+1);
        int c=LCS(s1.substr(1),s2.substr(1),ans,i+1,j+1);
        //save for future
        ans[i][j]=max(a,max(b,c));
    }
    return ans[i][j];


}


int LCS(string s1,string s2)
{
    int x=s1.size();
    int y=s2.size();
    int **ans=new int*[x+1];
    for(int i=0;i<=x;i++)
    {
        ans[i]=new int[y+1];
    }
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            ans[i][j]=-1;
        }
    }

    return LCS(s1,s2,ans);
}
*/


//DP



int LCS(string s1,string s2)
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

            int ans1=-1,ans2=-1,ans3=-1;
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
                    ans[i][j]=1+ans3;
                }
                else
                {
                    ans[i][j]=1;
                }
                continue;
            }
            ans[i][j]=max(ans1,max(ans2,ans3));

        }
    }
    return ans[0][0];
}



int main()
{
    string a,b;
    cin>>a>>b;
    int ans=LCS(a,b);
    cout<<ans<<endl;

}
