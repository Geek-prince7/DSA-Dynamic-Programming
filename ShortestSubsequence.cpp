#include <iostream>
#include <string>
#include<climits>
using namespace std;

/*
int solve(string s, string v,string out="") {
    // Write your code here
    if(s.size()==0)
    {
        return INT_MAX;
    }
    if(v.size()==1)
    {
        return out.size();
    }
    if(v.size()==0)
    {

        return out.size()+1;
    }
    //cout<<s.substr(1)<<" "<<v<<endl;
    int ans1=solve(s.substr(1),v,out);
    char c=s[0];
    int i=0;
    for(i;i<v.size();i++)
    {
        if(v[i]==c)
        {
            break;
        }
    }

    if(i>=v.size())
    {
        i--;
    }

   // cout<<s.substr(1)<<" "<<v.substr(i+1)<<endl;
    int ans2=solve(s.substr(1),v.substr(i+1),out+s[0]);
    if(ans1==INT_MAX && ans2==INT_MAX)
    {
        return INT_MAX;
    }

    else
    {
        return min(ans1,ans2);
    }




}
*/

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);

}
