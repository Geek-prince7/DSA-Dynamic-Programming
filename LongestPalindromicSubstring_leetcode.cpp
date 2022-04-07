#include<iostream>
#include<string>
using namespace std;
int palin(string s)
{
    int j=s.size()-1;
    int i=0;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return s.size();
}
string longestPalindrome(string s)
{
    string updated="$";
    for(int i=0;i<s.size();i++)
    {
        updated+='#';
        updated+=s[i];
    }
    updated+="#@";
    //pending

}

/*
string palin(string s)
{
    int j=s.size()-1;
    int i=0;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return "";
        }
        i++;
        j--;
    }
    return s;
}

string longestPalindrome(string s)
{
    int n=s.size();
    string **dp=new string*[n];
    int maxL=0;
    string maxS="";
    for(int i=0;i<n;i++)
    {
        dp[i]=new string[n];
        int l=1;
        for(int j=i;j<n;j++)
        {
            string k=s.substr(i,l);
            l++;
            //cout<<"value of k is : "<<k<<"  ";
            dp[i][j]=palin(k);
            //cout<<"palin of k is : "<<dp[i][j]<<endl;
            if(dp[i][j].size()>maxL)
            {
                maxL=k.size();
                maxS=dp[i][j];
            }

        }
    }
    return maxS;
}
*/

int main()
{
    string s;
    cin>>s;

    cout<<longestPalindrome(s);
    //cout<<palin(s);
}
