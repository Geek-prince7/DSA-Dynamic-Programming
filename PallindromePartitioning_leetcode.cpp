#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;

    // Reverse the string P
    reverse(P.begin(), P.end());

    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}



int partition(string s)
{
    if(s.size()==1 || s.size()==0)
    {
        return 1;
    }
    if(isPalindrome(s))
    {
        return 1;
    }
    string fh="",sh="";
    int mini=1;
    for(int i=0;i<s.size();i++)
    {
        fh+=s[i];
        sh=s.substr(i+1);
        cout<<"s is :"<<s<<" fh is :"<<fh<<" sh is :"<<sh<<endl;
        int ans1=partition(fh);
        int ans2=partition(sh);
        if(mini>min(ans1,ans2))
        {
            mini+=min(ans1,ans2);
        }


    }
    return mini;

}

int main()
{
    string s;
    cin>>s;
    cout<<"s is :"<<s<<endl;
    cout<<partition(s);
    /*
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    */
}
