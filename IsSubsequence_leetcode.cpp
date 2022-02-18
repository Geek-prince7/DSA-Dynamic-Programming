#include<iostream>
using namespace std;
/*
bool isSubsequence(string s,string t,string out="")
{
    if(s==out)
    {
        return true;
    }
    if(t.size()==0)
    {
        //cout<<out<<endl;
        return false;
    }

    bool ans1=isSubsequence(s,t.substr(1),out+t[0]);
    if(ans1)
    {
        return true;
    }
    bool ans2=isSubsequence(s,t.substr(1),out);

    return (ans1||ans2);
}
*/
bool isSubsequence(string s,string t,string out="")
{
    if(s.size()==0)
    {
        return true;
    }
    if(t.size()==0)
    {
        return false;
    }
    if(s[0]==t[0])
    {
        s=s.substr(1);
    }
    bool ans1=isSubsequence(s,t.substr(1));
    return ans1;
}
int main()
{
    string s,t;
    cin>>s>>t;
    if(isSubsequence(s,t))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}
