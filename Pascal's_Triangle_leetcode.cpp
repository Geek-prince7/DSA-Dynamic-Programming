#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++)
    {
        vector<int> out;
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i)
            {
                out.push_back(1);
            }
            else
            {
                out.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
        }
        ans.push_back(out);
    }
    return ans;


}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> ans=generate(n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
